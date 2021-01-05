cmake_minimum_required(VERSION 2.8)
project(consoleman)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(
    ${CMAKE_SOURCE_DIR}/include/
)
include_directories(
    ${CMAKE_SOURCE_DIR}/src/
)

file(GLOB source_files
            "*.h"
            "*.cpp"
            "src/*.cpp"
            "include/*.h"
    )

add_executable( consoleman
                ${source_files} )   
target_link_libraries(consoleman ${CURSES_LIBRARIES})
target_link_libraries(consoleman ${CMAKE_THREAD_LIBS_INIT})