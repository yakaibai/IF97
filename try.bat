mingw32-make
mingw32-make exe
echo off
for /L %%i in (300,10,800) do h_pT 0.1 %%i >> Enthalpy.csv