cmake_minimum_required(VERSION 3.22)
project(lab_02)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_02 main.cpp BaseVector.h AVector.hpp AVector.h Error.cpp Error.h BaseVectorIter.h ConstAVectorIter.hpp ConstAVectorIter.h AVectorIter.hpp AVectorIter.h)
