cmake_minimum_required(VERSION 3.20)

# ARGUMENTS
option(PLATFORM "PLATFORM" null)
option(LIBTYPE "LIBTYPE" "shared")
# set(ENV{LD_RUN_PATH} '$ORIGIN/lib')

project(mystd)

# set(SOURCES src/*.c)
FILE(GLOB_RECURSE SOURCES src/*.c)
if (${LIBTYPE} STREQUAL "static")
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
else()
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
endif()
