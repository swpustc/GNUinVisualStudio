::install.bat
@echo off
setlocal

echo This script will add the current path to environment and uncompress projects.
echo;
set "ENV_REG_ALL=HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment"
set "ENV_REG_CUR=HKCU\Environment"
set "KEY_SET=GNUDir"
set "GNU_DIR=%~dp0"
REM Directory Setting
set "ETC_DIR=etc"
set "INC_DIR=include"
set "PRO_DIR=project"
set "TOL_DIR=tools"
set "VST_DIR=vstudio"
set "TMP_DIR=tmp"

if not exist "%GNU_DIR%%ETC_DIR%" goto :use_env_dir
if not exist "%GNU_DIR%%INC_DIR%" goto :use_env_dir
if not exist "%GNU_DIR%%PRO_DIR%" goto :use_env_dir
if not exist "%GNU_DIR%%TOL_DIR%" goto :use_env_dir
if not exist "%GNU_DIR%%VST_DIR%" goto :use_env_dir
goto :set_env_dir
:use_env_dir
set "GNU_DIR=%GNUDir%"
if           "%GNU_DIR%" == ""    goto :empty_env_dir
if not exist "%GNU_DIR%"          goto :empty_env_dir
if not exist "%GNU_DIR%%ETC_DIR%" goto :empty_env_dir
if not exist "%GNU_DIR%%INC_DIR%" goto :empty_env_dir
if not exist "%GNU_DIR%%PRO_DIR%" goto :empty_env_dir
if not exist "%GNU_DIR%%TOL_DIR%" goto :empty_env_dir
if not exist "%GNU_DIR%%VST_DIR%" goto :empty_env_dir
echo Cur key [GNUDir]: %GNU_DIR%
echo;
goto :start
:set_env_dir
if /i "%~1" == "c"   goto :set_env_cur
if /i "%~1" == "cur" goto :set_env_cur
if /i "%~1" == "a"   goto :set_env_all
if /i "%~1" == "all" goto :set_env_all
if /i "%~1" == "s"    goto :skip_set_env
if /i "%~1" == "skip" goto :skip_set_env
cls
echo Old key [GNUDir]: %GNUDir%
echo New key [GNUDir]: %GNU_DIR%
echo;
set "setup_env=cur"
if defined GNUDir if /i "%GNUDir%" == "%GNU_DIR%" set "setup_env=skip"
set /p "setup_env=Setup %KEY_SET% for current user or all user? (cur/all/skip) [default=%setup_env%] "
echo;
if    "%setup_env%" == ""    goto :skip_set_env
if /i "%setup_env%" == "c"   goto :set_env_cur
if /i "%setup_env%" == "cur" goto :set_env_cur
if /i "%setup_env%" == "a"   goto :set_env_all
if /i "%setup_env%" == "all" goto :set_env_all
if /i "%setup_env%" == "s"    goto :skip_set_env
if /i "%setup_env%" == "skip" goto :skip_set_env
goto :set_env_dir
:set_env_cur
set "ENV_REG=%ENV_REG_CUR%"
set "ENV_REG_DEL=%ENV_REG_ALL%"
goto :setup_env_dir
:set_env_all
set "ENV_REG=%ENV_REG_ALL%"
set "ENV_REG_DEL=%ENV_REG_CUR%"
goto :setup_env_dir
:setup_env_dir
echo Delete key [%KEY_SET%] in
echo     %ENV_REG_DEL%
reg delete "%ENV_REG_DEL%" /v %KEY_SET% /f > nul 2>&1
echo Add key [%KEY_SET%] to
echo     %ENV_REG%
reg add "%ENV_REG%" /v %KEY_SET% /t REG_EXPAND_SZ /f /d "%GNU_DIR%\" > nul 2>&1
echo;
goto :start
:skip_set_env
goto :use_env_dir

:empty_env_dir
echo $(GNUDir) is not set, please run install.bat in the right directory first.
exit /b 1

:start
echo Done.
ping 127.1 -n 5 > nul
goto :eof
