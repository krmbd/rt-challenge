#include <catch2/catch_test_macros.hpp>

#include "vector.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("A Vector is a tuple with w = 0", "[vector][tuple][ch1]")
{
    REQUIRE(Vector::w == 0);
}
// NOLINTEND(cert-err58-cpp)
