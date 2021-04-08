# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.7)
project(OS2021Project)
set(CMAKE_CXX_STANDARD 20)

add_executable(OS2021Project main.cpp sourcesFiles/Family.cpp headersFiles/Family.h headersFiles/main.h sourcesFiles/randomString.cpp headersFiles/randomString.h sourcesFiles/WardRobe.cpp headersFiles/WardRobe.h sourcesFiles/Cloth.cpp headersFiles/Cloth.h sourcesFiles/Member.cpp headersFiles/Member.h)
