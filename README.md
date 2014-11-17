breakout
========

My breakout game  

Command line options  
-fullscreen  
-windowed  
-640x480  
-800x600  
-1024x768  
-1280x720  
-1920x1080  
-noborder  

### Compile on linux using g++
git clone  
cd breakout  
mkdir build  
cd build  
cmake -DCMAKE_BUILD_TYPE=Release ..  
make  
./jonesybreakout  


### Compile on windows using mingw
git clone  
cd breakout  
mkdir build  
cd build  
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..  
mingw32-make  
jonesybreakout.exe  

### Compile on Mac
coming soon  