
find_package(libigl CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics REQUIRED)

#find_package(Stb REQUIRED)
 
add_subdirectory(nvolib)
add_subdirectory (tester)

option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

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

if(INSTALL_TARGET)
    install(DIRECTORY "${LIBIGL_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*libpng16d.dll*"
    )
endif()
if(INSTALL_TARGET)
    install(DIRECTORY "${SFML_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*sfml-graphics-d-2.dll*"
    )
    install(DIRECTORY "${SFML_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*sfml-system-d-2.dll*"
    )
    install(DIRECTORY "${SFML_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*sfml-window-d-2.dll*"
    )
endif()
install(TARGETS nvolib DESTINATION bin)
install(DIRECTORY nvolib/include/ DESTINATION include/nvolib)
install(FILES nvolib/nvolib.cpp nvolib/include/nvolib/nvolib.hpp DESTINATION include/nvolib)

#install(TARGETS tester DESTINATION bin)
install(DIRECTORY tester/ DESTINATION bin/tester)
install(FILES tester/tester.cpp DESTINATION bin/tester)
install(FILES tester/CMakeLists.txt DESTINATION bin/tester)


install(FILES CMakeLists.txt DESTINATION .)
install(FILES nvolib/CMakeLists.txt DESTINATION nvolib)

install(DIRECTORY cmake/ DESTINATION .)
