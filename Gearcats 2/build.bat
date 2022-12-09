@echo off
where pros > NUL
IF %ERRORLEVEL% NEQ 0 (GOTO :notOk)
pros make
GOTO :end

:notOk
ECHO pros is not found, make sure you are in the pros terminal or have it installed.


:end