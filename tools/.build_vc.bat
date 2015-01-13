::tools/.build_vc.bat
@echo off
setlocal

if not defined GNU_SLNDIR goto :error
if not defined VS_VERSION goto :error

if not defined GNUDir goto :empty_env
set "SLN_DIR=%GNUDir%vstudio\%GNU_SLNDIR%\gnu.sln"
set "ETC_DIR=%GNUDir%etc\%GNU_SLNDIR%\"
set "TOOLS_DIR=%GNUDir%tools\"

if not exist "%SLN_DIR%"                    goto :error
if not exist "%TOOLS_DIR%.getdevenvdir.bat" goto :error
if not exist "%TOOLS_DIR%.build_macro.bat"  goto :error

call "%TOOLS_DIR%.getdevenvdir.bat" %VS_VERSION%
if errorlevel 1 goto :explain

call "%TOOLS_DIR%.build_macro.bat" %*
goto :eof

:explain
echo This command prompt environment is not initialized correctly to include
echo awareness of the VS%VS_VERSION% installation.  To run this file in the correct
echo environment, click "Microsoft Visual Studio %VS_VERSION%" then "Visual Studio Tools"
echo then "Visual Studio Command Prompt (%VS_VERSION%)" and run this .bat file from the
echo resulting command window.
echo;
goto :eof

:empty_env
echo $(GNUDir) is not set in environment.  Please run install.bat to setup and
echo restart your system.
echo;
goto :end

:error
echo It needs to be run from build.bat
echo;
goto :end

:end
pause
goto :eof
