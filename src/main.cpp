#include <iostream>

#include "point.hpp"
#include "vector.hpp"

struct Projectile
{
    Point position;
    Vector velocity;
};

struct Environment
{
    Vector gravity;
    Vector wind;
};

Projectile tick(Environment env, Projectile proj)
{
    const Point position = proj.position + proj.velocity;
    const Vector velocity = proj.velocity + env.gravity + env.wind;

    return Projectile{ position, velocity };
}

int main()
{
    Projectile proj{ Point{ 0, 1, 0 }, Normalize(Vector{ 1, 1, 0 }) };
    const Environment env{ Vector{ 0, -0.1, 0 }, Vector{ -0.01, 0, 0 } };

    unsigned int turn{ 0 };
    while (proj.position.y > 0)
    {
        std::cout << "Turn " << turn << ": The projectile is at position " << proj.position << "\n";
        proj = tick(env, proj);
        turn++;
    }

    return 0;
}
