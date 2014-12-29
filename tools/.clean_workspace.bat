::tools/.clean_workspace.bat
@echo off
setlocal

if not defined DIST_CLEAN goto :error
if not defined GNUDir set "GNUDir=%~dp0..\"
set "COPY_BAT=%GNUDir%tools\.copy.bat"
set "ETC_DIR=%GNUDir%etc\"
set "PRO_DIR=%GNUDir%project\"

echo Deleteing generation files in the workspace ...
call "%COPY_BAT%" remove_ifexist "%GNUDir%bin"
call "%COPY_BAT%" remove_ifexist "%GNUDir%dll"
call "%COPY_BAT%" remove_ifexist "%GNUDir%lib"
call "%COPY_BAT%" remove_ifexist "%GNUDir%bsc"
call "%COPY_BAT%" remove_ifexist "%GNUDir%pdb"
call "%COPY_BAT%" remove_ifexist "%GNUDir%pdb_pub"
call "%COPY_BAT%" remove_ifexist "%GNUDir%map"
call "%COPY_BAT%" remove_ifexist "%GNUDir%tmp"
if /i "%DIST_CLEAN%" == "t"    set "DIST_CLEAN=true"
if /i "%DIST_CLEAN%" == "true" call :dist_clean
goto :eof

:dist_clean
for /f "delims=" %%i in ('dir /ad /b "%ETC_DIR%"') do call "%COPY_BAT%" remove_ifexist "%ETC_DIR%%%~i\addressTable.txt" "%ETC_DIR%%%~i\addressTable"
for /f "usebackq delims=" %%i in ("%PRO_DIR%.dist_clean") do call "%COPY_BAT%" remove_ifexist "%PRO_DIR%%%i"
goto :eof

:error
echo It needs to be run from clean.bat
echo;
pause
goto :eof
