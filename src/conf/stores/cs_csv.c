

static int escape_csv(char *dest, const char *src);
static char *getfield(char *);

static struct ConfStoreHandle *open_csv(char *, struct ConfStoreField *);
static int read_csv(struct ConfStoreHandle *, va_list);
static int close_csv(struct ConfStoreHandle *);
static int append_csv(char *, struct ConfStoreField *, va_list);
static int delete_csv(char *, struct ConfStoreField *, va_list);

struct ConfStoreHandle {
  FBFILE *fptr;
  struct ConfStoreField *fields;
};

static struct ConfStoreFunctions csv_store = {
  open_csv, read_csv, close_csv,
  append_csv, delete_csv
};

INIT_MODULE(cs_csv, "$Revision$")
{
  register_store_backend(&csv_store);
}

CLEANUP_MODULE
{
  deregister_store_backend(&csv_store);
}


static struct ConfStoreHandle *
open_csv(char *name, struct ConfStoreField *fields)
{
  struct ConfStoreHandle *result;

  result = MyMalloc(sizeof(struct ConfStoreHandle));
  result->fields = fields;

  result->fptr = fbopen(name, "rt");
  if (result->fptr == NULL)
  {
    MyFree(result);
    return NULL;
  }

  return result;
}

static int
read_csv(struct ConfStoreHandle *handle, va_list args)
{
  char buf[2*IRCD_BUFSIZE], *nextfield;
  int i;
  char **strval;
  int *intval;
  time_t *timeval;

  if (handle == NULL)
    return 0; // Umm... I guess open failed...

  // Try reading a line...
  if (fbgets(buf, sizeof(buf), handle->fptr) == NULL)
  {
    return 0; // no more lines
  }

  if ((nextfield = strchr(buf, '\n')) != NULL)
    *nextfield = '\0';

  for(i=0, nextfield=buf; store[i].type && nextfield; i++)
  {
    char *field = nextfield;

    // Note: this also removes escapes from the current field.
    nextfield = getfield(field);

    switch(store[i].type)
    {
    case CSF_NONE:
      (void) va_arg(args, void *); // Throw it away
      break;

    case CSF_STRING:
    case CSF_STRING_MATCH_CASE:
      strval = va_arg(args, char **);
      if (strval != NULL)
        DupString(*strval, field);
      break;

    case CSF_NUMBER:
      intval = va_arg(args, int *);
      if (intval != NULL)
        *intval = atoi(field);
      break;

    case CSF_DATETIME:
      timeval = va_arg(args, time_t *);
      if (timeval != NULL)
        *timeval = atol(field);
      break;
    }
  }

  return 1; // Seems we just read a line...
}

static int
close_csv(struct ConfStoreHandle *handle)
{
  if (handle != NULL)
  {
    fbclose(handle->fptr);
    handle->fptr = NULL;
    MyFree(handle);
  }
  return 0;
}

static int
append_csv(char *name, struct ConfStoreField *fields, va_list args)
{
  char *out, buf[2*IRCD_BUFSIZE]; // paranoia
  int i;
  char *strval;
  int intval;
  time_t timeval;
  FBFILE *outfile = fbopen(*name, "at");
  if (outfile == NULL)
    return -1; // Error opening file

  for(i=0; fields[i].type; i++)
  {
    if (i > 0)
      *out++ = ',';

    switch(store[i].type)
    {
    case CSF_NONE:
      (void) va_arg(args, void *); // Throw it away
      break;

    case CSF_STRING:
    case CSF_STRING_MATCH_CASE:
      strval = va_arg(args, char *);
      out += escape_csv(out, strval);
      break;

    case CSF_NUMBER:
      intval = va_arg(args, int);
      out += sprintf(buf, "%d", intval);
      break;

    case CSF_DATETIME:
      timeval = va_arg(args, time_t);
      out += sprintf(buf, "%lu", timeval);
    }
  }

  *out++ = '\n';
  *out = '\0';
  fbputs(buf, outfile, out - buf);
  fbclose(outfile);

  return 0;
}

// TBD: Improve error reporting
static int
delete_csv(char *name, struct ConfStoreField *fields, va_list args)
{
  char buf[2*IRCD_BUFSIZE], buff[2*IRCD_BUFSIZE], temppath[IRCD_BUFSIZE];
  int i, oldumask, matches=0;
  char **strval, *nextfield;
  int *intval;
  time_t *timeval;
  static FBFILE *outfile, *infile = fbopen(*store->file, "rt");
  if (infile == NULL)
    return -1; // Error opening file

  ircsprintf(temppath, "%s.tmp", name);
  oldumask = umask(0);
  outfile = fbopen(temppath, "wt")
  umask(oldumask);

  if (outfile == NULL)
  {
    fbclose(infile);
    return -1;
  }

  while(fbgets(buf, sizeof(buf), infile) != NULL)
  {
    int isMatch=1;
    /* Keep a copy of the old line, getfield trashes it as it goes
     * TBD: Would it be worth writing it now, and fseek()ing back if match?
     */
    strlcpy(buff, buf, sizeof(buff));

    if ((nextfield = strchr(buf, '\n')) != NULL)
      *nextfield = '\0';

    // see read_csv() for more info about this loop
    for(i=0, nextfield=buf; matches && store[i].type && nextfield; i++)
    {
      char *field = nextfield;
      nextfield = getfield(nextfield);

      switch(store[i].type)
      {
      case CSF_NONE:
        (void) va_arg(args, void *); // Throw it away
        break;

      case CSF_STRING:
        strval = va_arg(args, char **);
        if ((strval != NULL) && irccmp(*strval, field))
          isMatch = 0;
        break;

      case CSF_STRING_MATCH_CASE:
        strval = va_arg(args, char **);
        if ((strval != NULL) && strcmp(*strval, field))
          isMatch = 0;
        break;

      case CSF_NUMBER:
        intval = va_arg(args, int *);
        if ((intval != NULL) && (*intval != atoi(field)))
          isMatch = 0;
        break;

      case CSF_DATETIME:
        timeval = va_arg(args, time_t *);
        if ((timeval != NULL) && (*timeval != atoi(field)))
          isMatch = 0;
        break;
      }
    }

    if (isMatch)
      matches++
    else
      if (fbputs(buff, outfile, strlen(buff)) < 0)
      { // eep, error. let's not trash half the klines, and just bail out.
        fbclose(infile);
        fbclose(outfile);
        unlink(temppath);
        return -1;
      }
  }

  fbclose(infile);
  fbclose(outfile);
  rename(temppath, name);

  return matches;
}


static int
escape_csv(char *dest, const char *src)
{
  char *output = dest;

  if (strchr(input, ','))
    *output++ = '"';

  for( ; *input; *output++ = *input++)
    if ((*input == '"') || (*input == '\\'))
      *output++ = '\\';

  // Did we escape a comma?
  if (*dest == '"')
    *output++ = '"';

  *output = '\0';
  return output - dest;
}

static char *
getfield(char *rest)
{
  char *src = rest, *dest = rest;
  int inquotes = 0;

  /* So, we walk the string, 'copying' it into itself.
   * This way, we can eat escapes and don't need an extra buffer.
   */
  for(; *src; src++)
  {
    if (*src == '\\')
    {
      if (*++src == '\0') // Trailing backslash? Confused!
        break;
      *dest++ = *src;
    }
    else if (*src == ',' && !inquotes)
      break;
    else if (*src == '"')
      inquotes = !inquotes;
    else
      *dest++ = *src;
  }

  // Do we have another field?
  if (*src == ',')
    src++;
  else // *src == '\0'
    src = NULL
  // Terminate current field
  *dest = '\0';
  // Return start of next field
  return src;
}
