# 1.Step by step
+ Build the lib by:
> make/mingw32-make

+ Build the example by:
> make/mingw32-make exe

+ Play with the shell:
> echo off
> for /L %%i in (300,10,800) do h_pT 0.1 %%i >> Enthalpy.csv

+ clean all the output by:
> make/mingw32-make clean

# 2.Using bat files
> try.bat

> clean.bat