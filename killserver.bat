@echo off
setlocal enabledelayedexpansion

set PORT=3000

for /f "tokens=5" %%a in ('netstat -ano ^| findstr 0.0.0.0:2247') do (
    set PID=%%a
    taskkill /F /PID !PID!
)

endlocal