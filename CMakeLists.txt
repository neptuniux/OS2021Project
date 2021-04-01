# cmake_minimum_required(VERSION <specify CMake version here>)
project(OS2021Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(OS2021Project main.cpp Family.cpp Family.h main.h randomString.cpp randomString.h testCloths.cpp testCloths.h WardRobe.cpp WardRobe.h Cloth.cpp Cloth.h Member.cpp Member.h)