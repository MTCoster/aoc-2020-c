cmake_minimum_required(VERSION 3.17)
project(AOC_2020_C C)

set(CMAKE_C_STANDARD 11)

include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported OUTPUT ipo_check_error)

if(ipo_supported)
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not supported: <${ipo_check_error}>")
endif()

include_directories(src)

add_library(file_utils OBJECT src/file_utils.c)

add_library(day01 OBJECT src/day01.c)
add_executable(day01a src/cmd/day01a.c $<TARGET_OBJECTS:day01> $<TARGET_OBJECTS:file_utils>)
add_executable(day01b src/cmd/day01b.c $<TARGET_OBJECTS:day01> $<TARGET_OBJECTS:file_utils>)

add_library(day02 OBJECT src/day02.c)
add_executable(day02a src/cmd/day02a.c $<TARGET_OBJECTS:day02> $<TARGET_OBJECTS:file_utils>)
add_executable(day02b src/cmd/day02b.c $<TARGET_OBJECTS:day02> $<TARGET_OBJECTS:file_utils>)

add_library(day03 OBJECT src/day03.c)
add_executable(day03a src/cmd/day03a.c $<TARGET_OBJECTS:day03> $<TARGET_OBJECTS:file_utils>)
add_executable(day03b src/cmd/day03b.c $<TARGET_OBJECTS:day03> $<TARGET_OBJECTS:file_utils>)
