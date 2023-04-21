#include <catch2/catch_test_macros.hpp>

#include "util.hpp"
#include "vector.hpp"

// NOLINTBEGIN(cert-err58-cpp)
TEST_CASE("A Vector is a tuple with w = 0", "[vector][tuple][ch1]")
{
    REQUIRE(Vector::w == 0);
}

TEST_CASE("Output stream operator of a Vector", "[vector][tuple]")
{
    const Vector vector{ -4, -5, -6 };

    std::ostringstream stream;
    stream << vector;

    std::string expectedOutput = "{ -4, -5, -6 }";
    std::string actualOutput = stream.str();

    REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("Equality for two almost-equal Vectors", "[vector]")
{
    const Vector vector1{ 1, 2, 3 };
    const Vector vector2{ 1, 2, 3 - EPSILON / 2 };

    REQUIRE(vector1 == vector2);
}

TEST_CASE("Equality for two slightly different Vectors", "[vector]")
{
    const Vector vector1{ 1, 2, 3 };
    const Vector vector2{ 1, 2, 3 - EPSILON * 2 };

    REQUIRE(vector1 != vector2);
}
// NOLINTEND(cert-err58-cpp)
