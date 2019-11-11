cmake_minimum_required(VERSION 3.8)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/Singleton/singleton.h
        src/Singleton/singleton.cpp
        src/Singleton/singleton-v2.cpp
        src/Strategy/strategy.h
        src/Strategy/strategy.cpp
        src/Observer/observer.cpp
        src/Observer/observer.h)

add_executable(DesignPattern ${SOURCE_FILES})