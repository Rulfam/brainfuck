cmake_minimum_required(VERSION 4.0)
project(brainfuck LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Libraries

add_library(compiler STATIC lib/compiler.cc)
target_include_directories(compiler PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(machine STATIC lib/machine.cc)
target_include_directories(machine PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(runner STATIC lib/runner.cc)
target_include_directories(runner PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Final compilation

add_executable(${PROJECT_NAME} src/main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE compiler machine runner)
