
cmake_minimum_required(VERSION 3.0)

project(CArray 
        LANGUAGES C
        VERSION 1.0)

file(GLOB SOURCES ../src/*.c)
file(GLOB HEADERS ../include/*.h)
file(GLOB BENCHMARK_SOURCES ../test/Benchmark/*.c)

if(MSVC)
    set(CMAKE_C_FLAGS "/W4 /D_CRT_SECURE_NO_DEPRECATE")
    set(CMAKE_C_FLAGS_DEBUG "/DEBUG /Od /DDEBUG /D_DEBUG /DLOG")
    set(CMAKE_C_FLAGS_RELEASE "/Ox /GL /LTCG /DNDEBUG")
else()
    set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic -Wfloat-equal")
    set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG -DLOG")
    set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG -mtune=native -march=native -fopenmp")
    set(CMAKE_LINK_FLAGS_RELEASE "-flto -fopenmp")
endif()

add_executable(Benchmark ${BENCHMARK_SOURCES} ${SOURCES})

set_target_properties(Benchmark PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../bin)

target_include_directories(Benchmark PUBLIC ../include)