cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)

if (BUILD_WITH_CODEFORCES)
    add_subdirectory(prj.codeforces)
endif()

#find_package(doctest REQUIRED)
add_subdirectory(prj.cw)
add_subdirectory(prj.codeforces)

