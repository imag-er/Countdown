cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_C_COMPILER "cc")
set(CMAKE_CXX_COMPILER "c++")
project(Countdown VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows -municode")

include(CTest)
enable_testing()
set(CMAKE_EXE_LINKER_FLAGS"${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
add_executable(Countdown
    main.cpp
    Core/Core.cpp
    MainWindow/MainWindowProcDetail.cpp
    MainWindow/SetMainWindow.cpp
    Premiere/Premiere.cpp
    ToolFunc/Exception.cpp
)
target_link_directories(Countdown
    PUBLIC
    Core/
    MainWindow/
    Premiere/
    ToolFunc/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
