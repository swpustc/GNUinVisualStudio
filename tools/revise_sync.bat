::revise_sync.bat
@echo off
setlocal

echo This script will synchronize project_revise and project directory.
echo;

set "GNUDir=%~dp0..\"

xcopy /d /s /y /h    "%GNUDir%project_revise" "%GNUDir%project\"
xcopy /d /s /y /h /u "%GNUDir%project"        "%GNUDir%project_revise\"
echo;

echo Done.
ping 127.1 -n 5 >nul
goto :eof
