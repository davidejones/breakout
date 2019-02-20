breakout
========

[![screenshot](https://raw.githubusercontent.com/davidejones/breakout/master/screen.png)](https://github.com/davidejones/breakout)

## Running the game

**Command line options**
```bash
Usage: breakout.exe <option(s)>
Options:
        -h,--help               Show this help message
        -fullscreen             Open fullscreen window
        -windowed               Open windowed
        -640x480                640x480 resolution in windowed mode
        -800x600                800x600 resolution in windowed mode
        -1024x768               1024x768 resolution in windowed mode
        -1280x720               1280x720 resolution in windowed mode
        -1920x1080              1920x1080 resolution in windowed mode
        -noborder               borderless window in windowed mode
```

## Compile from source

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