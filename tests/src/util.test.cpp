#include <catch2/catch_test_macros.hpp>

#include "util.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("AreAlmostEqual returns true for two equal numbers", "[util]")
{
    const double lhs = 3983849.394;
    const double rhs = lhs;

    REQUIRE(AreAlmostEqual(lhs, rhs));
}

TEST_CASE("AreAlmostEqual returns false for two numbers that differ more than a defined epsilon", "util")
{
    const double epsilon = 0.001;
    const double lhs = 17.5;
    const double rhs = lhs - 2 * epsilon;

    REQUIRE_FALSE(AreAlmostEqual(lhs, rhs));
}
// NOLINTEND(cert-err58-cpp)
