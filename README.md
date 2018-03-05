# CMAKE gTest Prime Setup

When dealing with small projects a simple cmake with source files in a single 
folder may suffice.

    cmake_minimum_required ( VERSION 3.5 )
    project ( SimpleProject CXX )
    find_package ( <Necessary-package> REQUIRED )
    add_executable ( simplerun main.cpp )
    target_link_libraries ( main <package-or-library-string> )

However, as a project grows bigger, better organization is important.

This kickstarted setup helps you start new C++ CMAKE project. It also includes 
gTest (downloaded at compilation time) in order to provide a unitest framework.

## Folder structure
    
    .
    ├── cmake                   # CMAKE modules
    │   └── gtest.cmake
    ├── CMakeLists.txt
    ├── include                 # .h  files go here
    │   ├── CMakeLists.txt
    │   └── Example.h
    ├── lib                     # included external libraries go here
    │   └── CMakeLists.txt
    ├── src                     # .cpp files go here
    │   ├── CMakeLists.txt
    │   ├── Example.cpp
    │   └── main.cpp
    └── test                    # folder for test
        ├── CMakeLists.txt
        ├── example.cpp
        └── main.cpp

## Configuration

For your new project, it may be interesting for you to redefine the `project` 
name and the `binary` name. Both, marked with `TODO` can be changed in the 
project `CMakeList.txt` file in the project's root folder. 

Addtionally this project offers the following compilation setup options

    BUILD_INCLUDE_TESTS         # Build tests by default
    BUILD_SILENCE_WARNINGS      # Compilation warnings activated by default
    BUILD_WARNINGS_AS_ERRORS    # Treat all comp warnings as error not activated 

## How to build?

    // in the root directory
    mkdir build
    cd build
    cmake .. -DBUILD_WARNINGS_AS_ERRORS=ON
    make -j2

Output binary will be in `./build/bin/` folder. It can be called by 
