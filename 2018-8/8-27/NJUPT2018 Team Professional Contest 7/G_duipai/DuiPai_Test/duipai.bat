@echo off  
:loop  
    RAN.exe %random% > data.in
    baoli.exe < data.in > AC.out
    Lin.exe < data.in > WA.out
    fc AC.out WA.out 
if not errorlevel 1 goto loop  
pause
goto loop