#include <catch2/catch_test_macros.hpp>

#include "lib.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("Hello world")
{
    REQUIRE(helloworld() == "Hello, world!");
}
// NOLINTEND(cert-err58-cpp)
