# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.8)
project(OS2021Project)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/daniel/Qt5.12.10/5.12.10/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(OS2021Project
        main.cpp
        sourcesFiles/Family.cpp
        headersFiles/Family.h
        headersFiles/main.h
        sourcesFiles/randomString.cpp
        headersFiles/randomString.h
        sourcesFiles/WardRobe.cpp
        headersFiles/WardRobe.h
        sourcesFiles/Cloth.cpp
        headersFiles/Cloth.h
        sourcesFiles/Member.cpp
        headersFiles/Member.h
        gui/mainwindows.cpp
        gui/mainwindows.h
        gui/mainWindows.ui)

target_link_libraries(OS2021Project -lrt -lpthread -lm)
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
