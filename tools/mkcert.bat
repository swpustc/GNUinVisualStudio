::tools/mkcert.bat
@echo off
setlocal

if not defined GNUDir set "GNUDir=%~dp0..\"
call "%GNUDir%tools\.getdevenvdir.bat"
if errorlevel 1 call "%GNUDir%tools\.getdevenvdir.bat" VS2010
if errorlevel 1 call "%GNUDir%tools\.getdevenvdir.bat" VS2012
if errorlevel 1 call "%GNUDir%tools\.getdevenvdir.bat" VS2013
if errorlevel 1 goto :eof


:start
set START_STATE=
if not "%~1" == "" goto :start_2
:start_1
cls
echo This script will creat a self/sign certificate file or signs/verify files.
echo     0. Close.
echo     1. Creates a self-signed certificate.
echo     2. Creates a normal-signed certificate.
echo     3. Signs file with a signing certificate in a file.
echo     4. Verifies the digital signature of files by determining whether the
echo   signing certificate was issued by a trusted authority.
echo     5. Signs file when verifies digital signature failed.
set choose=0
set /p "choose=Please choose: (0/1/2/3/4/5) [default=%choose%] "
echo;
set "START_STATE=choose:%choose%"
if "%choose%" == "0" goto :eof
if "%choose%" == "1" goto :self_cert
if "%choose%" == "2" goto :sign_cert
if "%choose%" == "3" goto :make_sign
if "%choose%" == "4" goto :verify_sign
if "%choose%" == "5" goto :verify_failed_sign
goto :start_1
:start_2
if /i "%~1" == "self" goto :self_cert
if /i "%~1" == "r"    goto :self_cert
if /i "%~1" == "normal" goto :sign_cert
if /i "%~1" == "n"      goto :sign_cert
if /i "%~1" == "sign" goto :make_sign
if /i "%~1" == "s"    goto :make_sign
if /i "%~1" == "verify" goto :verify_sign
if /i "%~1" == "v"      goto :verify_sign
if /i "%~1" == "versign" goto :verify_failed_sign
if /i "%~1" == "vs"      goto :verify_failed_sign
goto :empty_entry


:self_cert
set "SELF_CERT_NAME=rootcert"
if     "%START_STATE%" == "" if not "%~2" == "" set "SELF_CERT_NAME=%~2"
if not "%START_STATE%" == "" set /p "SELF_CERT_NAME=Specifies the self-signed certificate file name: [default=%SELF_CERT_NAME%] "
if /i "%SELF_CERT_NAME:~-4,4%" == ".cer" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
if /i "%SELF_CERT_NAME:~-4,4%" == ".pvk" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
if /i "%SELF_CERT_NAME:~-4,4%" == ".pfx" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
set "CN_NAME=swpustc"
if     "%START_STATE%" == "" if not "%~3" == "" set "CN_NAME=%~3"
if not "%START_STATE%" == "" set /p "CN_NAME=Specifies the subject's certificate name: [default=%CN_NAME%] "
set "POLICY_INF=http://home.ustc.edu.cn/~swpustc"
if     "%START_STATE%" == "" if not "%~4" == "" set "POLICY_INF=%~4"
if not "%START_STATE%" == "" set /p "POLICY_INF=Specifies policy information: [default=%POLICY_INF%] "
set "VALIDITY_MONTHS=192"
if     "%START_STATE%" == "" if not "%~5" == "" set "VALIDITY_MONTHS=%~5"
if not "%START_STATE%" == "" set /p "VALIDITY_MONTHS=Specifies the duration(in months) of the validity period: [default=%VALIDITY_MONTHS%] "
makecert -n "CN=%CN_NAME%,OU=%CN_NAME%,O=University of Science and Technology of China.,L=Hefei,ST=Anhui,C=CN,Email=swpustc@mail.ustc.edu.cn" -r -b 01/01/%date:~0,4% -m %VALIDITY_MONTHS% -a sha256 -len 4096 -l "%POLICY_INF%" -sv "%SELF_CERT_NAME%.pvk" "%SELF_CERT_NAME%.cer"
if "%~6" == "" pause
goto :eof


:sign_cert
set "CERT_NAME=MyCert"
if     "%START_STATE%" == "" if not "%~2" == "" set "CERT_NAME=%~2"
if not "%START_STATE%" == "" set /p "CERT_NAME=Specifies the signed certificate file name: [default=%CERT_NAME%] "
if /i "%CERT_NAME:~-4,4%" == ".cer" set "CERT_NAME=%CERT_NAME:~0,-4%"
if /i "%CERT_NAME:~-4,4%" == ".pvk" set "CERT_NAME=%CERT_NAME:~0,-4%"
if /i "%CERT_NAME:~-4,4%" == ".pfx" set "CERT_NAME=%CERT_NAME:~0,-4%"
set "SELF_CERT_NAME=rootcert"
if     "%START_STATE%" == "" if not "%~3" == "" set "SELF_CERT_NAME=%~3"
if not "%START_STATE%" == "" set /p "SELF_CERT_NAME=Specifies your private key file name: [default=%SELF_CERT_NAME%] "
if /i "%SELF_CERT_NAME:~-4,4%" == ".cer" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
if /i "%SELF_CERT_NAME:~-4,4%" == ".pvk" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
if /i "%SELF_CERT_NAME:~-4,4%" == ".pfx" set "SELF_CERT_NAME=%SELF_CERT_NAME:~0,-4%"
set "CN_NAME=Test Cert"
if     "%START_STATE%" == "" if not "%~4" == "" set "CN_NAME=%~4"
if not "%START_STATE%" == "" set /p "CN_NAME=Specifies the subject's certificate name: [default=%CN_NAME%] "
set "POLICY_INF=https://git.ustclug.org/swp/gnuinvisualstudio"
if     "%START_STATE%" == "" if not "%~5" == "" set "POLICY_INF=%~5"
if not "%START_STATE%" == "" set /p "POLICY_INF=Specifies policy information: [default=%POLICY_INF%] "
set "VALIDITY_MONTHS=1"
if     "%START_STATE%" == "" if not "%~6" == "" set "VALIDITY_MONTHS=%~6"
if not "%START_STATE%" == "" set /p "VALIDITY_MONTHS=Specifies the duration(in months) of the validity period: [default=%VALIDITY_MONTHS%] "
makecert -n "CN=%CN_NAME%,OU=swpustc,O=University of Science and Technology of China.,L=Hefei,ST=Anhui,C=CN,Email=swpustc@mail.ustc.edu.cn" -m %VALIDITY_MONTHS% -a sha256 -len 4096 -l "%POLICY_INF%" -ic "%SELF_CERT_NAME%.cer" -iv "%SELF_CERT_NAME%.pvk" -sv "%CERT_NAME%.pvk" "%CERT_NAME%.cer"
if not "%errorlevel%" == "0" goto :eof
cert2spc "%CERT_NAME%.cer" "%CERT_NAME%.spc"
REM If you donot specifies password (-pi PSWORD) here, pvk2pfx will ask for you with an input box.
pvk2pfx -pvk "%CERT_NAME%.pvk" -pi "" -spc "%CERT_NAME%.spc" -pfx "%CERT_NAME%.pfx"
if "%~7" == "" pause
goto :eof


:make_sign
set "BIN_FILE=test.exe"
if     "%START_STATE%" == "" if not "%~2" == "" set "BIN_FILE=%~2"
if not "%START_STATE%" == "" set /p "BIN_FILE=Specifies the path to a file to sign: [default=%BIN_FILE%] "
set "CERT_NAME=MyCert"
if     "%START_STATE%" == "" if not "%~3" == "" set "CERT_NAME=%~3"
if not "%START_STATE%" == "" set /p "CERT_NAME=Specifies the signing certificate in a file: [default=%CERT_NAME%] "
if /i "%CERT_NAME:~-4,4%" == ".cer" set "CERT_NAME=%CERT_NAME:~0,-4%"
if /i "%CERT_NAME:~-4,4%" == ".pvk" set "CERT_NAME=%CERT_NAME:~0,-4%"
if /i "%CERT_NAME:~-4,4%" == ".pfx" set "CERT_NAME=%CERT_NAME:~0,-4%"
set "PFX_PASSWORD="
if     "%START_STATE%" == "" if not "%~4" == "" set "PFX_PASSWORD=%~4"
if not "%START_STATE%" == "" set /p "PFX_PASSWORD=Specifies the password to use when opening a PFX file: [default=%PFX_PASSWORD%] "
set "TIME_STAMP_URL=http://timestamp.verisign.com/scripts/timstamp.dll"
if     "%START_STATE%" == "" if not "%~5" == "" set "TIME_STAMP_URL=%~5"
if not "%START_STATE%" == "" set /p "TIME_STAMP_URL=Specifies the URL of the time stamp server: [default=%TIME_STAMP_URL%] "
if /i "%BIN_FILE:~-4,4%" == ".exe" goto :make_sign_next
if /i "%BIN_FILE:~-4,4%" == ".dll" goto :make_sign_next
if /i "%BIN_FILE:~-4,4%" == ".sys" goto :make_sign_next
if /i "%BIN_FILE:~-4,4%" == ".msi" goto :make_sign_next
if /i "%BIN_FILE:~-4,4%" == ".ocx" goto :make_sign_next
if     "%~6" == "" echo File cannot be signed: %BIN_FILE%
exit /b 0
:make_sign_next
if not "%~6" == "" signtool sign /q /t "%TIME_STAMP_URL%" /fd sha256 /p "%PFX_PASSWORD%" /f "%CERT_NAME%.pfx" "%BIN_FILE%"
if     "%~6" == "" signtool sign /v /t "%TIME_STAMP_URL%" /fd sha256 /p "%PFX_PASSWORD%" /f "%CERT_NAME%.pfx" "%BIN_FILE%"
echo;
if     "%~6" == "" pause
goto :eof


:verify_sign
set "BIN_FILE=test.exe"
if     "%START_STATE%" == "" if not "%~2" == "" set "BIN_FILE=%~2"
if not "%START_STATE%" == "" set /p "BIN_FILE=Specifies the path to a file to verify signature: [default=%BIN_FILE%] "
if /i "%BIN_FILE:~-4,4%" == ".exe" goto :verify_sign_next
if /i "%BIN_FILE:~-4,4%" == ".dll" goto :verify_sign_next
if /i "%BIN_FILE:~-4,4%" == ".sys" goto :verify_sign_next
if /i "%BIN_FILE:~-4,4%" == ".msi" goto :verify_sign_next
if /i "%BIN_FILE:~-4,4%" == ".ocx" goto :verify_sign_next
if     "%~3" == "" echo File cannot be verifyed: %BIN_FILE%
exit /b 0
:verify_sign_next
if not "%~3" == "" echo %BIN_FILE%
if not "%~3" == "" signtool verify /q /a /pa /tw "%BIN_FILE%" > nul
if not "%~3" == "" if errorlevel 1 signtool verify /q /a /pa /tw "%BIN_FILE%" > nul 2>&1
if     "%~3" == "" signtool verify /v /a /pa /tw "%BIN_FILE%"
if     "%~3" == "" if errorlevel 1 signtool verify /v /a /pa /tw "%BIN_FILE%" > nul 2>&1
if not "%~3" == "" if "%errorlevel%" == "0" echo This file has been signed. & echo;
if     "%~3" == "" pause
goto :eof


:verify_failed_sign
                call :verify_sign verify "%~2"                   "%~6"
if errorlevel 1 call :make_sign   sign   "%~2" "%~3" "%~4" "%~5" "%~6"
goto :eof


:empty_entry
if not defined PFX_FILE set "PFX_FILE=%~f1"
if "%PFX_FILE:~-4,4%" == ".pfx" set "PFX_FILE=%PFX_FILE:~0,-4%"
if exist "%PFX_FILE%.pfx" goto :empty_entry_start
set "PFX_FILE="

call :search_pfx_file_default_dir "%cd%\"
if "%errorlevel%" == "0" goto :empty_entry_start
call :search_pfx_file_default_dir "%cd%\..\"
if "%errorlevel%" == "0" goto :empty_entry_start
call :search_pfx_file_default_dir "%cd%\..\..\"
if "%errorlevel%" == "0" goto :empty_entry_start

call :search_pfx_file_default_dir "%~dp0"
if "%errorlevel%" == "0" goto :empty_entry_start
call :search_pfx_file_default_dir "%~dp0..\"
if "%errorlevel%" == "0" goto :empty_entry_start
call :search_pfx_file_default_dir "%~dp0..\..\"
if "%errorlevel%" == "0" goto :empty_entry_start

echo     Can not find the signing certificate PFX file, you can set pfx file path to
echo %%PFX_FILE%%, and set the password to use with the PFX file to %%PFX_PSWORD%%, and
echo set the URL of the time stamp server to %%TIME_STAMP%%.  Variable %%RETRYTIMES%%
echo is the number of retries signature failure.  If you do not set the last three
echo variables, it will using the default value.
echo     If variables %%FORCE_SIGN%% is defined and set to any value, this script
echo will signs files without verifies the digital signature.
echo     The default value is:
echo         %%PFX_PSWORD%% -^> NULL
echo         %%TIME_STAMP%% -^> http://timestamp.verisign.com/scripts/timstamp.dll
echo         %%RETRYTIMES%% -^> 5
echo         %%FORCE_SIGN%% -^> NULL
echo     You can set the above variables and restart this script.
set PFX_FILE=
exit /b 1
:search_pfx_file_default_dir
call :search_pfx_file "%~f1"
if "%errorlevel%" == "0" exit /b 0
call :search_pfx_file "%~f1common\"
if "%errorlevel%" == "0" exit /b 0
call :search_pfx_file "%~f1etc\"
if "%errorlevel%" == "0" exit /b 0
call :search_pfx_file "%~f1include\"
if "%errorlevel%" == "0" exit /b 0
exit /b 1
:search_pfx_file
if not exist "%~f1*.pfx" exit /b 3
for /f "delims=" %%i in ('dir /a-d /b /od "%~f1*.pfx"') do set "PFX_FILE=%~f1%%~i"
if "%PFX_FILE:~-4,4%" == ".pfx" set "PFX_FILE=%PFX_FILE:~0,-4%"
if exist "%PFX_FILE%.pfx" exit /b 0
exit /b 1

:empty_entry_start
echo The signing certificate PFX file path:
echo     %PFX_FILE%.pfx
echo;
call :empty_entry_1 %*
if not defined RET_FINISH pause
goto :eof
:empty_entry_1
if "%~f1" == "" exit /b 0
for /f "delims=" %%i in ('dir /a-d /s /b /od "%~f1"') do call :empty_entry_2 "%%~i"
goto :empty_entry_next
:empty_entry_2
if not exist "%~f1" exit /b 1
if not defined RETRYTIMES set "RETRYTIMES=5"
set "LEFT_RETRYTIMES=%RETRYTIMES%"
:empty_entry_sign
set /a LEFT_RETRYTIMES-=1
if %LEFT_RETRYTIMES% lss 0 goto :empty_entry_next
if     defined FORCE_SIGN call :make_sign        sign "%~f1" "%PFX_FILE%.pfx" "%PFX_PSWORD%" "%TIME_STAMP%" "no pause"
if not defined FORCE_SIGN call :verify_failed_sign vs "%~f1" "%PFX_FILE%.pfx" "%PFX_PSWORD%" "%TIME_STAMP%" "no pause"
if errorlevel 1 goto :empty_entry_sign
:empty_entry_next
shift /1
goto :empty_entry_1
