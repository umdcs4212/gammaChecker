cmake_minimum_required(VERSION 3.22)

project(gammaCheck
  VERSION 1.0
  LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

# Should be using at least C++17, but 20 is better, so
# make sure we switch to 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------------------------------------------------------------
# PNG and ZLIB
#
# This macro will attempt to locate the PNG include directories, link directories and libraries. The INCLUDE_DIRECTORIES
# macro adds the resulting include directories to the search path.
# --------------------------------------------------------------------
FIND_PACKAGE(PNG REQUIRED)
if(NOT PNG_FOUND)
  message(STATUS "Could not find the PNG Libraries!")
endif(NOT PNG_FOUND)

add_executable(genGammaImage
  genGammaImage.cpp
)

target_include_directories(genGammaImage PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(genGammaImage PRIVATE PNG::PNG)
target_link_libraries(genGammaImage PRIVATE ZLIB::ZLIB)
