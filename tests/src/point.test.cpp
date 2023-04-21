#include <catch2/catch_test_macros.hpp>

#include "point.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("A Point is a tuple with w = 1", "[point][tuple][ch1]")
{
    REQUIRE(Point::w == 1);
}
// NOLINTEND(cert-err58-cpp)
