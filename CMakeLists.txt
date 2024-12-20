cmake_minimum_required(VERSION 3.10)

project(Lab3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    src/main.c
    src/deque.c
    src/output_stream.c
    src/input_stream.c
    src/sorted.c
    src/generate_random_data.c
)

set(HEADERS
    include/lib.h
    include/input_stream.h
    include/output_stream.h
    include/generate_random_data.h
    include/sorted.h
    include/deque.h
)

include_directories(include)

add_executable(Lab3 ${SOURCES} ${HEADERS})

