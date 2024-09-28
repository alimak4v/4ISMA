cmake_minimum_required(VERSION 3.15)

project(4ISMA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(4isma main.cpp Button.cpp Button.h)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(4isma sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

message(STATUS "Target architecture: ${CMAKE_SYSTEM_PROCESSOR}")

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm64")
    message(STATUS "Building for Apple Silicon (arm64)")
    set(CMAKE_OSX_ARCHITECTURES "arm64")

endif()