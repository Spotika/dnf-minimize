# Ultralight react template
Welcome to the Ultralight React Project Template for windows! This template provides a streamlined setup for developing desktop applications with Ultralight, a lightweight and fast web framework, and React, a popular JavaScript library for building user interfaces.

## Getting started
### Dependencies
* python 3.10 or later
* Node.js (20.10.0 or higher) + npm (10.2.4 or higher)
* Visual Studio 2017 or later (select the C++ tools during install)
*  [CMake](https://cmake.org/download/) _(Add it to your PATH during install)_
* Ninja 1.10.2 or later
* [Ultralight windows SDK 1.3.0.](https://github.com/ultralight-ux/Ultralight/releases)

### Installation step by step

Clonning repo
```
git clone https://github.com/Spotika/ultralight-react-template-win.git
cd ./ultralight-react-template-win
```

You are now in the main project folder. Now you have to install all react dependencies.
```
cd ./react-user-interface
npm install
```
 
Edit `CmakeLists.txt` specifying the path to the ultralight sdk on line 26 of the file. `set(SDK_ROOT "path/to/ultralight/sdk/root")`

Then set name for your app on 87 line if the file. `set(APP_NAME yourAppName)`

### Compile and run

Run this from root directory.
```
cmake -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S . -B ./build
```

After this step, all the assembly files will be written to build

Launching the application
```
cd ./build
yourAppName.exe
```
**It 's important that the .exe file will be named the same as your application**

