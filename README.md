breakout
========

My breakout game

## Compile on linux using g++
git clone  
cd breakout  
mkdir build  
cd build  
cmake -DCMAKE_BUILD_TYPE=Release ..  
make  
./jonesybreakout  


## Compile on windows using mingw
git clone  
cd breakout  
mkdir build  
cd build  
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..  
mingw32-make  
jonesybreakout.exe  

## Compile on Mac