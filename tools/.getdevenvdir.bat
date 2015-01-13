::tools/.getdevenvdir.bat
@echo off

set "VS_Install_Dir="
call :setenv
if errorlevel 1 if /i "%~1" == ""       exit /b 1
REM Microsoft Visual Studio 2010
if errorlevel 1 if /i "%~1" == "10"     call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "100"    call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "10.0"   call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "vc10"   call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "vc100"  call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "vc10.0" call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "2010"   call :GetDevEnvDir "10.0"
if errorlevel 1 if /i "%~1" == "VS2010" call :GetDevEnvDir "10.0"
REM Microsoft Visual Studio 2012
if errorlevel 1 if /i "%~1" == "11"     call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "110"    call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "11.0"   call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "vc11"   call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "vc110"  call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "vc11.0" call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "2012"   call :GetDevEnvDir "11.0"
if errorlevel 1 if /i "%~1" == "VS2012" call :GetDevEnvDir "11.0"
REM Microsoft Visual Studio 2013
if errorlevel 1 if /i "%~1" == "12"     call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "120"    call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "12.0"   call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "vc12"   call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "vc120"  call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "vc12.0" call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "2013"   call :GetDevEnvDir "12.0"
if errorlevel 1 if /i "%~1" == "VS2013" call :GetDevEnvDir "12.0"
REM END
if errorlevel 1 call :GetDevEnvDir_FullPath "%~1"
if errorlevel 1 call :GetDevEnvDir_FullDir  "%~1"
goto :eof

:GetDevEnvDir
if errorlevel 1 call :GetDevEnvDir_FullDir "Microsoft Visual Studio %~1"
if errorlevel 1 call :GetDevEnvDir_FullDir "Visual Studio %~1"
goto :eof

:GetDevEnvDir_FullDir
set "Full_Dir="
set "Full_Dir=%~1"
if "%Full_Dir:~1,1%" == ":" exit /b 1
if errorlevel 1 call :GetDevEnvDir_FullDevice "C:" "%~1"
if errorlevel 1 call :GetDevEnvDir_FullDevice "D:" "%~1"
if errorlevel 1 call :GetDevEnvDir_FullDevice "E:" "%~1"
if errorlevel 1 call :GetDevEnvDir_FullDevice "F:" "%~1"
if errorlevel 1 call :GetDevEnvDir_FullDevice "G:" "%~1"
goto :eof

:GetDevEnvDir_FullDevice
if errorlevel 1 call :GetDevEnvDir_FullPath "%~1\%~2"
if errorlevel 1 call :GetDevEnvDir_FullPath "%~1\Program Files\%~2"
if errorlevel 1 call :GetDevEnvDir_FullPath "%~1\Program Files (x86)\%~2"
goto :eof

:GetDevEnvDir_FullPath
set "VS_Install_Dir=%~1\VC\"
call :setenv
goto :eof

:setenv
if exist "%VS_Install_Dir%vcvarsall.bat" call "%VS_Install_Dir%vcvarsall.bat" x86 > nul
if defined DevEnvDir ( if exist "%DevEnvDir%devenv.exe" exit /b 0 ) else ( exit /b 1 )
