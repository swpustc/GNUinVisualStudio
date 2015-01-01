::preprocess.bat
@echo off
setlocal

echo This script will preprocess sources files.
echo;

set "WORK_DIR=%~dp0"
%WORK_DIR:~0,2%
cd %WORK_DIR%

echo Test for git branch...
git checkout -f sources >nul 2>&1
if errorlevel 1 echo git is't exist or branch 'sources' checkout error. && exit /b 1
echo;

echo Reset to sources branch...
git branch -f projects-protected projects
git checkout -f projects >nul 2>&1 && git reset --hard sources >nul 2>&1
git reset projects-protected >nul 2>&1
git branch -D projects-protected
echo;

echo Remove unneeded files...
set MOVE_FILE_NUM_ALL=0
for /f "delims=" %%i in ('dir /ad /b') do call :remove_unneeded_files "%%i"
echo Removed %MOVE_FILE_NUM_ALL% files in all directorys
echo;

echo Deep clean...
set MOVE_FILE_NUM=0
for /f "delims=" %%i in ('dir /a-d /b /s *.cat     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.cegcc   2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.charset 2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.chi     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.chm     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.clp     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.com     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.conf    2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.contrib 2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.cp      2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.cs      2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.csproj  2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.css     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.cvs     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.diff    2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.err     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.header  2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.hp64    2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.hpgcc   2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.hpux    2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.hqx     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.htm     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.html    2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.m4      2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.rc2     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.sax     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b /s *.src     2^>nul') do del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1
echo Removed %MOVE_FILE_NUM% files
echo;

echo Remove BOM and add newline at end of file...
call ..\tools\removeBOM.sh . && git checkout sources -- preprocess.bat >nul
echo;

echo Add and commit...
git add --all :/ >nul 2>&1
git rm -f keepNameExt
git rm --cached preprocess.bat
git commit -sm "auto commit. process project directory(%DATE:~0,10%)" >nul 2>&1
echo;

echo Done.
del /f /a /q "%~f0" && ping 127.1 -n 5 >nul && exit

:remove_unneeded_files
echo Entry directory %~1
set MOVE_FILE_NUM=0
for /f "delims=" %%i in ('xcopy /s /y /h /l /exclude:keepNameExt "%~1" 2^>nul') do if exist "%%i" del /f /a /q "%%i" && set /a MOVE_FILE_NUM+=1 && set /a MOVE_FILE_NUM_ALL+=1
echo Removed %MOVE_FILE_NUM% files
echo Leave directory %~1
echo;
goto :eof