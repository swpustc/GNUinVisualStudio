::tools/.build_macro.bat
@echo off
setlocal

if not defined SLN_DIR goto :error
if not defined DevEnvDir goto :error
if not defined VS_VERSION goto :error
set "VSDevEnv=%DevEnvDir%devenv.com"
if not exist "%VSDevEnv%" goto :error
if not "%~1" == "" goto :argc
call :all
goto :eof

:argc
if "%~1" == "" goto :eof
call :%~1
shift /1
goto :argc


:clean
call :echo_configure Clean "Release DLL libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release DLL libcrt|Win32"
echo;
call :echo_configure Clean "Release DLL libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release DLL libcrt|x64"
echo;
call :echo_configure Clean "Debug DLL libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug DLL libcrt|Win32"
echo;
call :echo_configure Clean "Debug DLL libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug DLL libcrt|x64"
echo;
call :echo_configure Clean "Release DLL libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release DLL libcmt|Win32"
echo;
call :echo_configure Clean "Release DLL libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release DLL libcmt|x64"
echo;
call :echo_configure Clean "Debug DLL libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug DLL libcmt|Win32"
echo;
call :echo_configure Clean "Debug DLL libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug DLL libcmt|x64"
echo;

call :echo_configure Clean "Release Library libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release Library libcrt|Win32"
echo;
call :echo_configure Clean "Release Library libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release Library libcrt|x64"
echo;
call :echo_configure Clean "Debug Library libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug Library libcrt|Win32"
echo;
call :echo_configure Clean "Debug Library libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug Library libcrt|x64"
echo;
call :echo_configure Clean "Release Library libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release Library libcmt|Win32"
echo;
call :echo_configure Clean "Release Library libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Release Library libcmt|x64"
echo;
call :echo_configure Clean "Debug Library libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug Library libcmt|Win32"
echo;
call :echo_configure Clean "Debug Library libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /clean "Debug Library libcmt|x64"
echo;
goto :eof


REM Note that reported MSB3073 "build errors" for 'simple_plugin' and 'hierarchy'
REM projects are a demonstration of failed unit tests and are not actual build
REM errors.
:crtrd32
call :echo_configure Build "Release DLL libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Release DLL libcrt|Win32"
echo;
goto :eof
:crtrl32
call :echo_configure Build "Release Library libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Release Library libcrt|Win32"
echo;
goto :eof
:crtr32
call :crtrd32
call :crtrl32
goto :eof
:crtrd64
call :echo_configure Build "Release DLL libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Release DLL libcrt|x64"
echo;
goto :eof
:crtrl64
call :echo_configure Build "Release Library libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Release Library libcrt|x64"
echo;
goto :eof
:crtr64
call :crtrd64
call :crtrl64
goto :eof
:crtr
call :crtr32
call :crtr64
goto :eof

:crtdd32
call :echo_configure Build "Debug DLL libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug DLL libcrt|Win32"
echo;
goto :eof
:crtdl32
call :echo_configure Build "Debug Library libcrt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug Library libcrt|Win32"
echo;
goto :eof
:crtd32
call :crtdd32
call :crtdl32
goto :eof
:crtdd64
call :echo_configure Build "Debug DLL libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug DLL libcrt|x64"
echo;
goto :eof
:crtdl64
call :echo_configure Build "Debug Library libcrt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug Library libcrt|x64"
echo;
goto :eof
:crtd64
call :crtdd64
call :crtdl64
goto :eof
:crtd
call :crtd32
call :crtd64
goto :eof

:crt
call :crtr
call :crtd
goto :eof


:cmtrd32
call :echo_configure Build "Release DLL libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Release DLL libcmt|Win32"
echo;
goto :eof
:cmtrl32
call :echo_configure Build "Release Library libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Release Library libcmt|Win32"
echo;
goto :eof
:cmtr32
call :cmtrd32
call :cmtrl32
goto :eof
:cmtrd64
call :echo_configure Build "Release DLL libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Release DLL libcmt|x64"
echo;
goto :eof
:cmtrl64
call :echo_configure Build "Release Library libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Release Library libcmt|x64"
echo;
goto :eof
:cmtr64
call :cmtrd64
call :cmtrl64
goto :eof
:cmtr
call :cmtr32
call :cmtr64
goto :eof

:cmtdd32
call :echo_configure Build "Debug DLL libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug DLL libcmt|Win32"
echo;
goto :eof
:cmtdl32
call :echo_configure Build "Debug Library libcmt Win32"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug Library libcmt|Win32"
echo;
goto :eof
:cmtd32
call :cmtdd32
call :cmtdl32
goto :eof
:cmtdd64
call :echo_configure Build "Debug DLL libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug DLL libcmt|x64"
echo;
goto :eof
:cmtdl64
call :echo_configure Build "Debug Library libcmt x64"
"%VSDevEnv%" "%SLN_DIR%" /build "Debug Library libcmt|x64"
echo;
goto :eof
:cmtd64
call :cmtdd64
call :cmtdl64
goto :eof
:cmtd
call :cmtd32
call :cmtd64
goto :eof

:cmt
call :cmtr
call :cmtd
goto :eof


:rd32
call :crtrd32
call :cmtrd32
goto :eof
:rd64
call :crtrd64
call :cmtrd64
goto :eof
:crtrd
call :crtrd32
call :crtrd64
goto :eof
:cmtrd
call :cmtrd32
call :cmtrd64
goto :eof
:rd
call :crtrd
call :cmtrd
goto :eof

:rl32
call :crtrl32
call :cmtrl32
goto :eof
:rl64
call :crtrl64
call :cmtrl64
goto :eof
:crtrl
call :crtrl32
call :crtrl64
goto :eof
:cmtrl
call :cmtrl32
call :cmtrl64
goto :eof
:rl
call :crtrl
call :cmtrl
goto :eof

:r
call :rd
call :rl
goto :eof


:dd32
call :crtdd32
call :cmtdd32
goto :eof
:dd64
call :crtdd64
call :cmtdd64
goto :eof
:crtdd
call :crtdd32
call :crtdd64
goto :eof
:cmtdd
call :cmtdd32
call :cmtdd64
goto :eof
:dd
call :crtdd
call :cmtdd
goto :eof

:dl32
call :crtdl32
call :cmtdl32
goto :eof
:dl64
call :crtdl64
call :cmtdl64
goto :eof
:crtdl
call :crtdl32
call :crtdl64
goto :eof
:cmtdl
call :cmtdl32
call :cmtdl64
goto :eof
:dl
call :crtdl
call :cmtdl
goto :eof

:d
call :dd
call :dl
goto :eof


:dll32
call :rd32
call :dd32
goto :eof
:dll64
call :rd64
call :dd64
goto :eof
:dll
if not defined ETC_DIR goto :dll_start
set "BASEADDR_DATE_TIME_OLD=1970/1/1 00:00:00 0"
for /f "delims=" %%i in ('forfiles /p "%ETC_DIR%\" /m "addressTable.txt" /c "cmd /c echo @fdate @ftime @fsize" 2^> nul') do set "BASEADDR_DATE_TIME_OLD=%%i"
:dll_start
call :rd
call :dd
if not defined ETC_DIR goto :dll_end
set "BASEADDR_DATE_TIME_NEW=1970/1/1 00:00:00 1"
for /f "delims=" %%i in ('forfiles /p "%ETC_DIR%\" /m "addressTable.txt" /c "cmd /c echo @fdate @ftime @fsize" 2^> nul') do set "BASEADDR_DATE_TIME_NEW=%%i"
if /i "%BASEADDR_DATE_TIME_OLD%" == "%BASEADDR_DATE_TIME_NEW%" goto :dll_end
echo The BaseAddress table file `addressTable.txt' has been modified.
echo;
echo;
:dll_end
goto :eof


:lib32
call :rl32
call :dl32
goto :eof
:lib64
call :rl64
call :dl64
goto :eof
:lib
call :rl
call :dl
goto :eof


:all
if not defined ETC_DIR goto :all_start
set "BASEADDR_DATE_TIME_OLD=1970/1/1 00:00:00 0"
for /f "delims=" %%i in ('forfiles /p "%ETC_DIR%\" /m "addressTable.txt" /c "cmd /c echo @fdate @ftime @fsize" 2^> nul') do set "BASEADDR_DATE_TIME_OLD=%%i"
:all_start
call :crt
call :cmt
if not defined ETC_DIR goto :all_end
set "BASEADDR_DATE_TIME_NEW=1970/1/1 00:00:00 1"
for /f "delims=" %%i in ('forfiles /p "%ETC_DIR%\" /m "addressTable.txt" /c "cmd /c echo @fdate @ftime @fsize" 2^> nul') do set "BASEADDR_DATE_TIME_NEW=%%i"
if /i "%BASEADDR_DATE_TIME_OLD%" == "%BASEADDR_DATE_TIME_NEW%" goto :all_end
call :lib
call :dll
:all_end
goto :eof

:echo_configure
echo;
set /p = "========== VS%VS_VERSION% %~1:  %~2 ==========" < nul
goto :eof

:error
echo It needs to be run from tools\.build_vc.bat
echo;
pause
goto :eof
