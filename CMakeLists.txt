cmake_minimum_required(VERSION 3.5)

project(statistics)

add_executable(statistics main.cpp Pct.cpp Pct.h Min.cpp Min.h Max.cpp Max.h Sigma.cpp Sigma.h Mean.cpp Mean.h)
set_target_properties(statistics PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(statistics PUBLIC
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
            )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(statistics PUBLIC
            /EHsc
            /W4
            /WX
            )
endif()