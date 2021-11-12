cmake_minimum_required(VERSION 3.20)
project(Proga_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proga_lab main.cpp Complex.cpp Complex.h Tests.cpp ComplexWithData.cpp ComplexWithData.h ImprovedComplex.cpp ImprovedComplex.h Node.h List.h)
