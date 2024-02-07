cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

# add_executable("${PROJECT_NAME}" main.cc)

set(SOURCE_FILES
main.cc
class.cc
)

set(HEADER_FILES
class.h
defs.h
)

add_executable("${PROJECT_NAME}" ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties("${PROJECT_NAME}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories("${PROJECT_NAME}" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})