::tools/signture.bat
@echo off
setlocal

if not defined GNUDir set "GNUDir=%~dp0..\"

:setp1
if not exist "%GNUDir%etc\rootcert.cer" goto :GenSelfCert
if not exist "%GNUDir%etc\rootcert.pvk" goto :GenSelfCert
goto :step2
:GenSelfCert
if exist "%GNUDir%etc\rootcert.*" del "%GNUDir%etc\rootcert.*"
call "%GNUDir%tools\mkcert.bat" self "%GNUDir%etc\rootcert" "swpustc" "http://home.ustc.edu.cn/~swpustc" 192 "no-pause"
goto :step2

:step2
forfiles /p "%GNUDir%etc" /m MyCert.pfx /d -28 /c "cmd /c del @path & echo Certificate has expired." 2> nul
if not exist "%GNUDir%etc\MyCert.pfx" goto :GenNormalCert
goto :step3
:GenNormalCert
if exist "%GNUDir%etc\MyCert.*" del "%GNUDir%etc\MyCert.*"
call "%GNUDir%tools\mkcert.bat" normal "%GNUDir%etc\MyCert" "%GNUDir%etc\rootcert" "GNU Projects" "https://git.ustclug.org/swp/gnuinvisualstudio" 1 "no-pause"
goto :step3

:step3
if not defined PFX_FILE   set "PFX_FILE=%GNUDir%etc\MyCert"
if not defined PFX_PSWORD set "PFX_PSWORD="
if not defined NSPEC_PSWD if not defined PFX_PSWORD set /p "PFX_PSWORD=Specifies the pfx certificate file password: [default=%PFX_PSWORD%] "
if not defined TIME_STAMP set "TIME_STAMP="
if not defined RETRYTIMES set "RETRYTIMES=10"
if not defined FORCE_SIGN set "FORCE_SIGN="
if not defined RET_FINISH set "RET_FINISH="
call "%GNUDir%tools\mkcert.bat" "%GNUDir%bin" "%GNUDir%dll"
goto :eof
