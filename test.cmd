@echo off

for %%i in (??) do (
	echo ====^> %%i ^<====
	echo Input file: 
	type %%i
	echo.
	echo Output file:
	%1 < %%i
	echo.
)