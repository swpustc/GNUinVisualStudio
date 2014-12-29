::build.bat
@echo off
setlocal

echo This script will build projects with VisualStudio 2010/2012/2013.
if not defined GNUDir goto :show
%GNUDir:~0,2%
cd %GNUDir%
:show
echo The work directory is %cd%
echo;


if "%~1" == "" goto empty_entry
set "BUILD_VS2010=false"
set "BUILD_VS2012=false"
set "BUILD_VS2013=false"
set "BUILD_LABLE="
set "SIGN_BUILD_DONE=false"
set "SETUP_ENV_USER=skip"
:argc_argv
if "%~1" == "" goto :work
REM Microsoft Visual Studio 2010
if /i "%~1" == "10"     goto :set_build_vs2010
if /i "%~1" == "100"    goto :set_build_vs2010
if /i "%~1" == "10.0"   goto :set_build_vs2010
if /i "%~1" == "vc10"   goto :set_build_vs2010
if /i "%~1" == "vc100"  goto :set_build_vs2010
if /i "%~1" == "vc10.0" goto :set_build_vs2010
if /i "%~1" == "2010"   goto :set_build_vs2010
if /i "%~1" == "VS2010" goto :set_build_vs2010
REM Microsoft Visual Studio 2012
if /i "%~1" == "11"     goto :set_build_vs2012
if /i "%~1" == "110"    goto :set_build_vs2012
if /i "%~1" == "11.0"   goto :set_build_vs2012
if /i "%~1" == "vc11"   goto :set_build_vs2012
if /i "%~1" == "vc110"  goto :set_build_vs2012
if /i "%~1" == "vc11.0" goto :set_build_vs2012
if /i "%~1" == "2012"   goto :set_build_vs2012
if /i "%~1" == "VS2012" goto :set_build_vs2012
REM Microsoft Visual Studio 2013
if /i "%~1" == "12"     goto :set_build_vs2013
if /i "%~1" == "120"    goto :set_build_vs2013
if /i "%~1" == "12.0"   goto :set_build_vs2013
if /i "%~1" == "vc12"   goto :set_build_vs2013
if /i "%~1" == "vc120"  goto :set_build_vs2013
if /i "%~1" == "vc12.0" goto :set_build_vs2013
if /i "%~1" == "2013"   goto :set_build_vs2013
if /i "%~1" == "VS2013" goto :set_build_vs2013
REM END
if /i "%~1" == "cert"     goto :set_sign_build_done
if /i "%~1" == "sign"     goto :set_sign_build_done
if /i "%~1" == "signture" goto :set_sign_build_done
if /i "%~1" == "user_cur"  goto :setup_env_user_cur
if /i "%~1" == "user-cur"  goto :setup_env_user_cur
if /i "%~1" == "user:cur"  goto :setup_env_user_cur
if /i "%~1" == "user=cur"  goto :setup_env_user_cur
if /i "%~1" == "user_all"  goto :setup_env_user_all
if /i "%~1" == "user-all"  goto :setup_env_user_all
if /i "%~1" == "user:all"  goto :setup_env_user_all
if /i "%~1" == "user=all"  goto :setup_env_user_all
if /i "%~1" == "user_skip" goto :setup_env_user_skip
if /i "%~1" == "user-skip" goto :setup_env_user_skip
if /i "%~1" == "user:skip" goto :setup_env_user_skip
if /i "%~1" == "user=skip" goto :setup_env_user_skip
set "BUILD_LABLE=%BUILD_LABLE% %~1"
goto :argc_argv_end
:set_build_vs2010
set "BUILD_VS2010=true"
goto :argc_argv_end
:set_build_vs2012
set "BUILD_VS2012=true"
goto :argc_argv_end
:set_build_vs2013
set "BUILD_VS2013=true"
goto :argc_argv_end
:set_sign_build_done
set "SIGN_BUILD_DONE=true"
goto :argc_argv_end
:setup_env_user_cur
set "SETUP_ENV_USER=cur"
goto :argc_argv_end
:setup_env_user_all
set "SETUP_ENV_USER=all"
goto :argc_argv_end
:setup_env_user_skip
set "SETUP_ENV_USER=skip"
goto :argc_argv_end
:argc_argv_end
shift /1
goto :argc_argv

:empty_entry
set "BUILD_VS2010=true"
set /p "BUILD_VS2010=Whether to compile VS2010 projects? (true/false) [default=%BUILD_VS2010%] "
echo;
set "BUILD_VS2012=true"
set /p "BUILD_VS2012=Whether to compile VS2012 projects? (true/false) [default=%BUILD_VS2012%] "
echo;
set "BUILD_VS2013=true"
set /p "BUILD_VS2013=Whether to compile VS2013 projects? (true/false) [default=%BUILD_VS2013%] "
echo;
set "BUILD_LABLE=all"
echo For more information, see tools/.build_macro.bat
set /p "BUILD_LABLE=Specifies the build lable with a space: (crtrd32/cmt/dll/lib/...) [default=%BUILD_LABLE%] "
echo;
set "SIGN_BUILD_DONE=false"
set /p "SIGN_BUILD_DONE=Whether to signture PE files after build? (true/false) [default=%SIGN_BUILD_DONE%] "
echo;
if not defined GNUDir ( set "SETUP_ENV_USER=cur" ) else ( set "SETUP_ENV_USER=skip" )
if not defined GNUDir set /p "SETUP_ENV_USER=Setup GNUDir for current user or all user? (cur/all/skip) [default=%SETUP_ENV_USER%] "
if not defined GNUDir echo;
goto :work

:work
call :install
if /i "%BUILD_VS2010%" == "t"    set "BUILD_VS2010=true"
if /i "%BUILD_VS2010%" == "true" call :vs2010 %BUILD_LABLE%
if /i "%BUILD_VS2012%" == "t"    set "BUILD_VS2012=true"
if /i "%BUILD_VS2012%" == "true" call :vs2012 %BUILD_LABLE%
if /i "%BUILD_VS2013%" == "t"    set "BUILD_VS2013=true"
if /i "%BUILD_VS2013%" == "true" call :vs2013 %BUILD_LABLE%
if /i "%SIGN_BUILD_DONE%" == "t"    set "SIGN_BUILD_DONE=true"
if /i "%SIGN_BUILD_DONE%" == "true" call :sign_build_done
echo Done.
ping 127.1 -n 5 > nul
goto :eof


:install
if /i "%SETUP_ENV_USER%" == "c" set "SETUP_ENV_USER=cur"
if /i "%SETUP_ENV_USER%" == "a" set "SETUP_ENV_USER=all"
if /i not "%SETUP_ENV_USER%" == "cur" if /i not "%SETUP_ENV_USER%" == "all" set "SETUP_ENV_USER=skip"
if /i not "%SETUP_ENV_USER%" == "skip" call install.bat "%SETUP_ENV_USER%"
goto :eof

:vs2010
set "GNU_SLNDIR=vc10"
set "VS_VERSION=2010"
call tools\.build_vc.bat %*
goto :eof

:vs2012
set "GNU_SLNDIR=vc11"
set "VS_VERSION=2012"
call tools\.build_vc.bat %*
goto :eof

:vs2013
set "GNU_SLNDIR=vc12"
set "VS_VERSION=2013"
call tools\.build_vc.bat %*
goto :eof

:sign_build_done
REM Set these parameters to null to using the default value in tools/signture.bat
set "PFX_FILE="
set "PFX_PSWORD="
set "NSPEC_PSWD=true"
set "TIME_STAMP="
set "RETRYTIMES="
set "FORCE_SIGN="
set "RET_FINISH=true"
call tools\signture.bat
goto :eof
