@echo off                                        

for /D %%i in (a; b; c; d; e; f; g; h; i; j; k; l; m; n; o; p; r; s; t; u; v; w; x; y; z) do (
	mkdir %%i > NUL
	cd %%i > NUL
	if [%2] == [file] (
		copy C:\code\pattern\fpat.cpp %%i.cpp > NUL
	) else (
		copy C:\code\pattern\pat.cpp %%i.cpp > NUL
	)             
              

	cd ..
	if [%1]==[%%i] (
        	exit
        )	
)