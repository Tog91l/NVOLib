Cmake_minimum_required(VERSION 3.12)
project(nvolib)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file" -G Ninja)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg target triplet")
#set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}C:\vcpkg")

set(SFML_DIR "${VCPKG_ROOT}/installed/x64-windows/share/SFML")
find_package(libigl CONFIG REQUIRED)
 find_package(SFML COMPONENTS graphics REQUIRED)
#find_package(SFML CONFIG REQUIRED)
find_package(Stb REQUIRED)
 
add_subdirectory(nvolib)
add_subdirectory (tester)

if(WIN32)
    set(libigl_RUNTIME_PATH "${LIBIGL_INCLUDE_DIRS}/../../bin")
else()
    set(libigl_RUNTIME_PATH "${LIBIGL_INCLUDE_DIRS}/../../lib")
endif()
if(WIN32)
    set(sfml_RUNTIME_PATH "${SFML_INCLUDE_DIRS}/../../bin")
else()
    set(l_RUNTIME_PATH "${SFML_INCLUDE_DIRS}/../../lib")
endif()