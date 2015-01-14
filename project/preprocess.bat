::preprocess.bat
@echo off
setlocal

echo This script will preprocess sources files.
echo;

set "WORK_DIR=%~dp0"
%WORK_DIR:~0,2%
cd %WORK_DIR%

REM keep the space because the newline could be LF
git checkout -q sources -- preprocess.bat &&                REM

echo Test for git branch...
git checkout -fq sources
git show --oneline --quiet
if errorlevel 1 echo git is't exist. && exit /b 1
echo;

echo Reset to sources branch...
git branch -f projects-protected projects
git checkout -fq projects && git reset --hard -q sources
git reset -q projects-protected
git branch -D projects-protected
call ..\tools\merge_sources.sh
echo;

echo Preprocess blitz...
set MOVE_FILE_NUM=0
for /f "delims=" %%i in ('xcopy /s /y /h /exclude:xcopyExclude blitz\blitz blitz\include\blitz\ 2^>nul') do if exist "%%i" del /f /a /q "%%i" && echo %%i && set /a MOVE_FILE_NUM+=1
echo Moved %MOVE_FILE_NUM% files
echo;

echo Preprocess crypto++...
set MOVE_FILE_NUM=0
if not exist cryptopp\crypto++ mkdir cryptopp\crypto++
for /f "delims=" %%i in ('dir /a /b cryptopp') do if /i not "%%~i" == "crypto++" move /y "cryptopp\%%~i" cryptopp\crypto++\ >nul && echo cryptopp\%%~i && set /a MOVE_FILE_NUM+=1
echo Moved %MOVE_FILE_NUM% files
echo;

echo Preprocess gmp...
set MOVE_FILE_NUM=0
for /f "delims=" %%i in ('dir /a-d /b "gmp\mpf\*.c"') do ren "gmp\mpf\%%~i" "mpf_%%~i" && echo gmp\mpf\mpf_%%~i && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b "gmp\mpq\*.c"') do ren "gmp\mpq\%%~i" "mpq_%%~i" && echo gmp\mpq\mpq_%%~i && set /a MOVE_FILE_NUM+=1
for /f "delims=" %%i in ('dir /a-d /b "gmp\mpz\*.c"') do ren "gmp\mpz\%%~i" "mpz_%%~i" && echo gmp\mpz\mpz_%%~i && set /a MOVE_FILE_NUM+=1
echo Renamed %MOVE_FILE_NUM% files
del /f /a /q gmp\mpn\generic\gmp-mparam.h && echo gmp\mpn\generic\gmp-mparam.h
echo Removed 1 file
echo;

echo Preprocess libsigc++...
set MOVE_FILE_NUM=0
for /f "delims=" %%i in ('xcopy /s /y /h /exclude:xcopyExclude libsigc++\sigc++ libsigc++\include\sigc++\ 2^>nul') do if exist "%%i" del /f /a /q "%%i" && echo %%i && set /a MOVE_FILE_NUM+=1
echo Moved %MOVE_FILE_NUM% files
echo;

echo Preprocess xmlrpc-c...
setlocal
cd xmlrpc-c\Windows
set "DATE=%DATE:~0,10% by swpustc"
call ConfigureWin32.bat
endlocal
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
call ..\tools\removeBOM.sh . && git checkout -q sources -- preprocess.bat
echo;

echo Add and commit...
git add --all :/ 2>nul
git rm -f keepNameExt
git rm -f xcopyExclude
git rm --cached preprocess.bat
git commit -qsm "auto merge commit. process project directory(%DATE:~0,10%)" 2>nul
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
