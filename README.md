# About
Welcome to the Ultralight React Project Template for windows! This template provides a streamlined setup for developing desktop applications with Ultralight, a lightweight and fast web framework, and React, a popular JavaScript library with **TypeScript** implementation for building user interfaces.

# Why is this technology needed? 🤔
To implement a beautiful and supported frontend and backend in C++, there are the following popular technologies:
* SFML
* QT
Some information about this toolchains
## SFML
[About SFML](https://www.sfml-dev.org)
#### Advantages
* Simple and fast
* low level graphics in primitives provides the best control
* Good for simple game dev or for special projects
#### Disadvantages
* It is not intended to create a UI out of the box. To do this, you need to spend time implementing the basic components for the basic layout
## QT
[About QT](https://www.qt.io)
#### Advantages
* You can fast create simple UI and connect it co c++
* Qt designer and Qt creator instruments
* A lot of widgets written earlier that solve most problems
#### Disadvantages
* Hard to design and apply styles
* Hard to use animations

Both of these technologies have a number of disadvantages. For developing user interface you write much more terrible and routine code then you can write in React and connect it to ultralight.

## ✨ Ultralight + React ✨
#### Advantages 
* A common technology for writing an interface using React.
* You can design interface in online with dynamic updates using react-scripts
* You can use majority of HTML5 functions like animations, metadata and other
* SCSS styling
* TypeScript support
* You can link C++ with JS
#### Disadvantages 
* This is currently only available for windows (*there is no version for Linux and Mac*😢)
* You need more than one tool for work (Node.js, Python, C++). **installation guide**

# Getting started
## Installation
### Requires
* Node.js
* CMake
* Visual Studio >= 2017
* Python >= 3.10
* Serve
* [Ultralight windows SDK](https://github.com/ultralight-ux/Ultralight/releases)

### Ultralight SDK
Download [SDK](https://github.com/ultralight-ux/Ultralight/releases/download/v1.3.0/ultralight-sdk-1.3.0-win-x64.7z) (download link), extract it and remember path to SDK.


Clone repo and it will be your project root

```sh
git clone https://github.com/Spotika/ultralight-react-template-win.git ./my-ultralight-project
cd ./my-ultralight-project
```

Install react dependences
```sh
cd ./react-user-interface
npm install
```

Install serve if you don\`t have
```
npm install --global serve
```

## Building and running
To run correctly, you need to do the following things:
### Configure CmakeLists.txt
All lines of the file that need to be changed are marked with the comment "TODO"
* Change name of your project name `3: project(YourProjectName C CXX)` 
* Change app name `86: set(APP_NAME youtAppName)` it will be build target
* Set path to ultralight SDK `26: set(SDK_ROOT "C:/path/to/ultralight")`

### For Clion
You can open `my-ultralight-project` and set Visual Studio toolchain. Then clion will build and run project with ninja.

### For pure cmake
Now you in `my-ultralight-project`
```sh
cmake -B ./build
cmake --build ./build
```

Then you can find `.exe` with name of your app file in directory `./build/Debug/`

> Important! You should run `.exe` only from `./build` folder: `cd ./build && ./Debug/yourAppName.exe` it will be fixed soon.

# Roadmap
## Readme
- [ ] About extending application ❌
- [ ] About JS binding ❌
## Ultralight
- [ ] Multi threading system, that provides parallel calculation and rendering ❌
- [ ] More flexible configuretion ❌
- [ ] Add support for linux ❌
