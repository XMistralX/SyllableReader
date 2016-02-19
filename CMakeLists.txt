cmake_minimum_required(VERSION 3.3)
project(SyllableReaderProj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -liconv")

set(SOURCE_FILES main.cpp )
add_executable(SyllableReaderProj ${SOURCE_FILES})
add_library(SyllableReaderLib STATIC reader.cpp)
target_link_libraries(SyllableReaderProj SyllableReaderLib)