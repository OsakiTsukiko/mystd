cmake_minimum_required(VERSION 3.20)

# ARGUMENTS
set(ENV{LD_RUN_PATH} '$ORIGIN/../')

project(testpb)

# set(SOURCES main.c)
FILE(GLOB_RECURSE SOURCES src/*.c)
add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE ../../src/types)
target_link_directories(${PROJECT_NAME} PRIVATE ../)
target_link_libraries(${PROJECT_NAME} PRIVATE mystd)