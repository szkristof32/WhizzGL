cmake_minimum_required(VERSION 3.28)
project(WhizzGL C)

set(CMAKE_C_STANDARD 99)

file(GLOB HEADERS include/*.h)
file(GLOB SOURCES src/*.c)

add_library(WhizzGL STATIC ${SOURCES} ${HEADERS})
target_include_directories(WhizzGL PRIVATE include)

add_executable(Tester src/test.c)
target_include_directories(Tester PRIVATE include)
target_link_libraries(Tester WhizzGL)
target_link_libraries(Tester opengl32)
