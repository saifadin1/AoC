cmake_minimum_required(VERSION 3.22)

project(AdventOfCode2024)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HELPERS_SRC utils/helpers.cpp)
set(HELPERS_HEADER utils/helpers.h)

include_directories(${CMAKE_SOURCE_DIR}/utils)

add_library(helpers STATIC ${HELPERS_SRC})

file(GLOB_RECURSE DAY_SOURCES "2024/day*/part*.cpp")

foreach(SOURCE_FILE IN LISTS DAY_SOURCES)
    get_filename_component(FILENAME ${SOURCE_FILE} NAME)
    
    string(REGEX MATCH "day([0-9]+)" DAY_MATCH ${SOURCE_FILE})
    string(REGEX REPLACE "day([0-9]+)" "\\1" DAY ${DAY_MATCH})
    
    string(REGEX MATCH "part([0-9]+)" PART_MATCH ${FILENAME})
    string(REGEX REPLACE "part([0-9]+)" "\\1" PART ${PART_MATCH})
    
    set(EXEC_NAME "d${DAY}_p${PART}")
    
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
    target_link_libraries(${EXEC_NAME} PRIVATE helpers)
endforeach()
