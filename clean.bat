::clean.bat
@echo off
setlocal

echo This script will clean VS2010/2012/2013 generation files.
if not defined GNUDir goto :show
%GNUDir:~0,2%
cd %GNUDir%
:show
echo The work directory is %cd%
echo;


if "%~1" == "" goto empty_entry
set "CLEAN_VS2010=false"
set "CLEAN_VS2012=false"
set "CLEAN_VS2013=false"
set "CLEAN_WORKSPACE=false"
set "DIST_CLEAN=false"
:argc_argv
if "%~1" == "" goto :work
REM Microsoft Visual Studio 2010
if /i "%~1" == "10"     goto :set_clean_vs2010
if /i "%~1" == "100"    goto :set_clean_vs2010
if /i "%~1" == "10.0"   goto :set_clean_vs2010
if /i "%~1" == "vc10"   goto :set_clean_vs2010
if /i "%~1" == "vc100"  goto :set_clean_vs2010
if /i "%~1" == "vc10.0" goto :set_clean_vs2010
if /i "%~1" == "2010"   goto :set_clean_vs2010
if /i "%~1" == "VS2010" goto :set_clean_vs2010
REM Microsoft Visual Studio 2012
if /i "%~1" == "11"     goto :set_clean_vs2012
if /i "%~1" == "110"    goto :set_clean_vs2012
if /i "%~1" == "11.0"   goto :set_clean_vs2012
if /i "%~1" == "vc11"   goto :set_clean_vs2012
if /i "%~1" == "vc110"  goto :set_clean_vs2012
if /i "%~1" == "vc11.0" goto :set_clean_vs2012
if /i "%~1" == "2012"   goto :set_clean_vs2012
if /i "%~1" == "VS2012" goto :set_clean_vs2012
REM Microsoft Visual Studio 2013
if /i "%~1" == "12"     goto :set_clean_vs2013
if /i "%~1" == "120"    goto :set_clean_vs2013
if /i "%~1" == "12.0"   goto :set_clean_vs2013
if /i "%~1" == "vc12"   goto :set_clean_vs2013
if /i "%~1" == "vc120"  goto :set_clean_vs2013
if /i "%~1" == "vc12.0" goto :set_clean_vs2013
if /i "%~1" == "2013"   goto :set_clean_vs2013
if /i "%~1" == "VS2013" goto :set_clean_vs2013
REM END
if /i "%~1" == "all"       goto :set_clean_workspace
if /i "%~1" == "allclean"  goto :set_clean_workspace
if /i "%~1" == "all_clean" goto :set_clean_workspace
if /i "%~1" == "all-clean" goto :set_clean_workspace
if /i "%~1" == "workspace" goto :set_clean_workspace
if /i "%~1" == "dist"       goto :set_clean_dist
if /i "%~1" == "all_dist"   goto :set_clean_dist
if /i "%~1" == "all-dist"   goto :set_clean_dist
if /i "%~1" == "distclean"  goto :set_clean_dist
if /i "%~1" == "dist_clean" goto :set_clean_dist
if /i "%~1" == "dist-clean" goto :set_clean_dist
goto :argc_argv_end
:set_clean_vs2010
set "CLEAN_VS2010=true"
goto :argc_argv_end
:set_clean_vs2012
set "CLEAN_VS2012=true"
goto :argc_argv_end
:set_clean_vs2013
set "CLEAN_VS2013=true"
goto :argc_argv_end
:set_clean_workspace
set "CLEAN_WORKSPACE=true"
goto :argc_argv_end
:set_clean_dist
set "DIST_CLEAN=true"
goto :argc_argv_end
:argc_argv_end
shift /1
goto :argc_argv

:empty_entry
set "CLEAN_WORKSPACE=false"
set /p "CLEAN_WORKSPACE=Whether to clean all generation files? (true/false) [default=%CLEAN_WORKSPACE%] "
echo;
if /i "%CLEAN_WORKSPACE%" == "t"    set "CLEAN_WORKSPACE=true"
if /i "%CLEAN_WORKSPACE%" == "true" goto :work
set "CLEAN_VS2010=false"
set /p "CLEAN_VS2010=Whether to clean VS2010 generation files? (true/false) [default=%CLEAN_VS2010%] "
echo;
set "CLEAN_VS2012=false"
set /p "CLEAN_VS2012=Whether to clean VS2012 generation files? (true/false) [default=%CLEAN_VS2012%] "
echo;
set "CLEAN_VS2013=false"
set /p "CLEAN_VS2013=Whether to clean VS2013 generation files? (true/false) [default=%CLEAN_VS2013%] "
echo;
set "DIST_CLEAN=false"
set /p "DIST_CLEAN=Whether to district clean the workspace (DEEP)? (true/false) [default=%DIST_CLEAN%] "
echo;
goto :work

:work
if /i "%DIST_CLEAN%" == "t"    set "DIST_CLEAN=true"
if /i "%DIST_CLEAN%" == "true" call :dist_clean
if /i "%CLEAN_WORKSPACE%" == "t"    set "CLEAN_WORKSPACE=true"
if /i "%CLEAN_WORKSPACE%" == "true" call :workspace
if /i "%CLEAN_VS2010%" == "t"    set "CLEAN_VS2010=true"
if /i "%CLEAN_VS2010%" == "true" call :vs2010
if /i "%CLEAN_VS2012%" == "t"    set "CLEAN_VS2012=true"
if /i "%CLEAN_VS2012%" == "true" call :vs2012
if /i "%CLEAN_VS2013%" == "t"    set "CLEAN_VS2013=true"
if /i "%CLEAN_VS2013%" == "true" call :vs2013
echo Done.
ping 127.1 -n 5 > nul
goto :eof


:vs2010
set "GNU_SLNDIR=vc10"
set "VS_VERSION=2010"
call tools\.clean_vc.bat
goto :eof

:vs2012
set "GNU_SLNDIR=vc11"
set "VS_VERSION=2012"
call tools\.clean_vc.bat
goto :eof

:vs2013
set "GNU_SLNDIR=vc12"
set "VS_VERSION=2013"
call tools\.clean_vc.bat
goto :eof

:workspace
set "CLEAN_VS2010=false"
set "CLEAN_VS2012=false"
set "CLEAN_VS2013=false"
call :vs2010
call :vs2012
call :vs2013
set "DIST_CLEAN=false"
call tools\.clean_workspace.bat
goto :eof

:dist_clean
set "CLEAN_WORKSPACE=false"
set "CLEAN_VS2010=false"
set "CLEAN_VS2012=false"
set "CLEAN_VS2013=false"
call :vs2010
call :vs2012
call :vs2013
set "DIST_CLEAN=true"
call tools\.clean_workspace.bat
goto :eof
