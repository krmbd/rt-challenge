cmake_minimum_required(VERSION 3.16)

include(cmake/prelude.cmake)

project(
    rt-challenge
    VERSION 0.1.0
    DESCRIPTION "Implementation of a Ray Tracer in C++, following \"The Ray Tracer Challenge\" book"
    HOMEPAGE_URL "https://github.com/krmbd/rt-challenge"
    LANGUAGES CXX
    )

include(cmake/variables.cmake)

# ---- Declare library ----
add_library(
    rt-lib OBJECT
    src/point.cpp
    src/vector.cpp
    )

target_compile_features(rt-lib PUBLIC cxx_std_20)
target_include_directories(rt-lib PUBLIC "${PROJECT_SOURCE_DIR}/src")

# ---- Declare executable ----
add_executable(rt-exe src/main.cpp)
add_executable(rt-challenge::exe ALIAS rt-exe)

set_property(TARGET rt-exe PROPERTY OUTPUT_NAME rt)
target_compile_features(rt-exe PRIVATE cxx_std_17)
target_link_libraries(rt-exe PRIVATE rt-lib)

# ---- Developer mode ----
if(rt-challenge_DEVELOPER_MODE)
    include(cmake/dev-mode.cmake)
endif()
