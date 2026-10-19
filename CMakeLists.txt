cmake_minimum_required(VERSION 3.25)

project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LAB1_SANITIZER "" CACHE STRING "Sanitizer to enable: address, undefined or empty")
set_property(CACHE LAB1_SANITIZER PROPERTY STRINGS "" address undefined)

add_executable(lab1
    src/main.cpp
    src/stats.cpp
)

target_compile_options(lab1 PRIVATE -Wall -Wextra -Wpedantic)

if(LAB1_SANITIZER STREQUAL "address")
    set(sanitizer_flags -fsanitize=address -fno-omit-frame-pointer)
elseif(LAB1_SANITIZER STREQUAL "undefined")
    set(sanitizer_flags -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer)
elseif(NOT LAB1_SANITIZER STREQUAL "")
    message(FATAL_ERROR "Unknown LAB1_SANITIZER value: ${LAB1_SANITIZER}")
endif()

if(sanitizer_flags)
    target_compile_options(lab1 PRIVATE ${sanitizer_flags})
    target_link_options(lab1 PRIVATE ${sanitizer_flags})
endif()

enable_testing()
add_test(NAME run_lab1 COMMAND lab1)
