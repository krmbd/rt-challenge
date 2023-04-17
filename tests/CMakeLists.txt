project(rt-challenge-tests LANGUAGES CXX)

find_package(Catch2 REQUIRED)

add_executable(rt-tests src/util.test.cpp)
target_compile_features(rt-tests PRIVATE cxx_std_20)
target_link_libraries(rt-tests PRIVATE Catch2::Catch2WithMain rt-lib)

include(Catch)
catch_discover_tests(rt-tests)
