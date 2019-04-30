#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <math.h>
#include "color.hpp"
#include "vec2.hpp"

class Circle
{
    public:
    Circle();
    Circle(float radius, Vec2 const& Centre);

    float cirumference() const;

    private:
    float radius_ = 0.0f;
    Vec2 Centre_{0.0f,0.0f};
};

#endif