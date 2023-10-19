## ubuntu22

### depend

```
sudo apt install python3-distutils bison
sudo apt-get install libx11-*
sudo apt-get install libx11*
sudo apt-get install libxcb-*
sudo apt-get install libxcb*
sudo apt install  libxrandr-dev
sudo apt install libxft-dev libxext-dev
sudo apt-get install libdbus-1-dev
sudo apt-get install libxtst-dev
```

opengl

```
sudo apt-get install libgl1-mesa-dev mesa-common-dev libglu1-mesa-dev
sudo apt install xorg-dev
sudo apt-get install libbz2-dev
```

### compile

```
mkdir build & cd build
cmake -DCMAKE_TOOLCHAIN_FILE="~/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake" 
    -DCMAKE_MAKE_PROGRAM="Unix Makefile" 
    -DCMAKE_C_COMPILER=/usr/bin/gcc 
    -DCMAKE_CXX_COMPILER=/usr/bin/g++ 
    -DCMAKE_C_COMPILER_FORCED=ON 
    -DCMAKE_CXX_COMPILER_FORCED=ON ..
```

