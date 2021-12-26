- [1. HelloQt](#1-helloqt)
  - [1.1. vcpkg (Windows C/C++ Package Managerment)](#11-vcpkg-windows-cc-package-managerment)
  - [1.2. CMake (Windows)](#12-cmake-windows)

# 1. HelloQt

## 1.1. vcpkg (Windows C/C++ Package Managerment)
Install vcpkg: <https://vcpkg.io/en/index.html>

```
git clone https://github.com/Microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
vcpkg install [packages to install]
vcpkg integrate install
```

## 1.2. CMake (Windows) 
Install CMake: <https://www.cmake.org>

```
mkdir build
cd build                                # "out-of-source" build
cmake ..                                # Configure the build
cmake --build . --config Release -j 6   # Actually build the binaries
```



