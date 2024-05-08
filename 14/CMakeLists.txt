cmake_minimum_required(VERSION 3.20)

project(14
    VERSION 1.0.0
    DESCRIPTION "14"
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wnarrowing -Werror=return-type)
endif()

# set(CMAKE_BUILD_TYPE Release)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# include(CTest)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_executable(14 src/main.cpp)
