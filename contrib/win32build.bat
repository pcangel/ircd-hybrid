@echo off

rem Don't change it unless you edit IRCD_PREFIX in setup-win32.h too!
set IRCD_PREFIX=C:\IRCD

if exist src\ircd.c goto start
if exist ..\src\ircd.c goto start2
echo Are you sure you are executing this from ircd-hybrid sources directory?
goto end

:start2
cd ..

:start
if %1'==msvc' goto build
if %1'==bcc' goto build

cls
echo.
echo IRCD-Hybrid Windows build script
echo (C) Copyright 2005 by the past and present ircd coders, and others.
echo.
echo Do you want to edit default ircd settings now? [Type YES or NO]
echo @echo off >yes.bat
echo edit contrib\setup-win32.h >>yes.bat
echo exit >>yes.bat
copy yes.bat y.bat >nul
echo @exit >no.bat
echo @exit >n.bat
%COMSPEC% /k prompt Your choice? 
del yes.bat
del no.bat
del y.bat
del n.bat

echo.
echo ------------------------------------------------
echo.
echo Which compiler do you want to use?
echo * If you are going to compile with Borland C++ Compiler, type: BCC
echo * If you want to use Microsoft Visual C++ Compiler, type: MSVC
echo @echo off >msvc.bat
echo call contrib\win32build msvc >>msvc.bat
echo exit >>msvc.bat
echo @echo off >bcc.bat
echo call contrib\win32build bcc >>bcc.bat
echo exit >>bcc.bat
%COMSPEC% /k prompt Your choice? 
del bcc.bat
del msvc.bat
goto end2

:build
echo.
echo *** Building ircd-hybrid
copy contrib\setup-win32.h include\setup.h >nul
copy nul include\unistd.h >nul

for %%a in (ircd.exe src\dynlink.c src\irc_reslib.c src\rsa.c libio\net\res.c libio\net\reslib.c) do if exist %%a del %%a
for %%a in (modules\m_challenge.c modules\m_cryptlink.c contrib\libc_vprintf.c contrib\example_module.c contrib\ip_cloaking.c) do if exist %%a del %%a

if %1'==msvc' goto msvc
set COMPILER=BCC
bcc32 -tWD -6 -O -w- -elibio.dll -DIN_LIBIO -I"include" -I"libio" libio\comm\comm.c libio\comm\fdlist.c libio\comm\fileio.c libio\comm\win32.c libio\mem\*.c libio\misc\*.c libio\net\*.c libio\string\*.c
if errorlevel 1 goto error
if not exist libio.dll goto error
implib libio.lib libio.dll
if errorlevel 1 goto error
if not exist libio.lib goto error
bcc32 -tW -6 -O -w- -eircd.exe -I"include" -I"libio" src\*.c modules\*.c modules\core\*.c contrib\*.c libio.lib
if errorlevel 1 goto error
if not exist ircd.exe goto error
for %%a in (rehash remotd kill) do bcc32 -tW -6 -O -w- -e%%a.exe -I"include" tools\win32\%%a.c
goto built

:msvc
set COMPILER=MSVC
cl /nologo /O2 /w /Felibio.dll /I"include" /I"libio" /DIN_LIBIO libio\comm\comm.c libio\comm\fdlist.c libio\comm\fileio.c libio\comm\win32.c libio\mem\*.c libio\misc\*.c libio\net\*.c libio\string\*.c user32.lib wsock32.lib /link /dll /subsystem:windows
if errorlevel 1 goto error
if not exist libio.dll goto error
if not exist libio.lib goto error
cl /nologo /O2 /w /Feircd.exe /I"include" /I"libio" src\*.c modules\*.c modules\core\*.c contrib\*.c user32.lib wsock32.lib libio.lib /link /subsystem:windows
if errorlevel 1 goto error
if not exist ircd.exe goto error
for %%a in (rehash remotd kill) do cl /nologo /O2 /w /Fe%%a.exe /I"include" tools\win32\%%a.c user32.lib /link /subsystem:windows

:built
if errorlevel 1 goto error
echo.
echo *** Installing ircd-hybrid into %IRCD_PREFIX% ...
echo.
if not exist %IRCD_PREFIX% md %IRCD_PREFIX%
for %%a in (bin etc help help\opers help\users logs messages) do if not exist %IRCD_PREFIX%\%%a md %IRCD_PREFIX%\%%a
copy libio.dll %IRCD_PREFIX%\bin >nul
copy ircd.exe %IRCD_PREFIX%\bin >nul
copy rehash.exe %IRCD_PREFIX%\bin >nul
copy remotd.exe %IRCD_PREFIX%\bin >nul
copy kill.exe %IRCD_PREFIX%\bin >nul
for %%a in (etc\*.conf etc\*.conf.quick) do copy %%a %IRCD_PREFIX%\etc >nul
for %%a in (cresv.conf dline.conf nresv.conf rkline.conf rxline.conf xline.conf kline.conf) do type nul >>%IRCD_PREFIX%\etc\%%a
for %%a in (help\opers\* help\users\*) do copy %%a %IRCD_PREFIX%\%%a >nul
for %%a in (messages\*.lang messages\README) do copy %%a %IRCD_PREFIX%\%%a >nul
echo *** Installation complete!
echo.
echo Remember to create the 'ircd.conf' file before actually starting the IRCD.
goto end

:error
echo.
echo The compilation has failed. Make sure the %COMPILER% compiler you choose 
echo is actually installed, and that you haven't accidentally corrupted
echo your setup.h file. A common problem is also not having the directory of
echo compiler binary in PATH environment variable.
if %COMPILER%==MSVC goto end
echo.
echo Borland C++ Compiler 5.5 users please remember to set up BCC32.CFG
echo in your C:\BCC\BIN directory (or wherever you installed it)!
echo It should contain two lines like -IC:\BCC\INCLUDE and -LC:\BCC\LIB.

:end
for %%a in (*.obj *.lib *.tds *.dll *.exp *.exe) do del %%a
echo.
pause
:end2
rem $Id$
