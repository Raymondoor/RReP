cmake_minimum_required(VERSION 3.10)

project("RReP")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${PROJECT_SOURCE_DIR}/src/oal/include")
add_executable("RReP" "main.cpp")

if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        # 64-bit
        set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/src/oal/libs/Win64")
    else()
        # 32-bit
        set(LIBRARY_PATH "${PROJECT_SOURCE_DIR}/src/oal/libs/Win32")
    endif()
endif()

find_library(OPENAL_LIBRARY NAMES openal al openal32 PATHS "${LIBRARY_PATH}")

target_link_libraries(RReP ${OPENAL_LIBRARY})