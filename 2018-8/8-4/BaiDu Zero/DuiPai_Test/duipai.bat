@echo off  
:loop  
    RAN.exe %random% > data.in
    AC.exe < data.in > std.out
    WA.exe < data.in > my.out
    fc my.out std.out 
if not errorlevel 1 goto loop  
pause
goto loop