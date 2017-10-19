@echo off

g++ stup.cpp -o stup111.exe
gcc sol.c  -std=c99 -o sol111.exe
g++ gen.cpp -o gen111.exe


for /L %%i in (1, 1, 1000) do (
	
	gen111.exe %%i > input

	sol111.exe < input > my_output
	stup111.exe < input > right_output

	fc my_output right_output > kek || exit

        echo Passed %%i..
)

