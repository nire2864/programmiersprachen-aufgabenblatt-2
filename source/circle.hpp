#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <math.h>
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Circle
{
    public:
    Circle();
    Circle(float radius, Vec2 const& centre, Color const& col);

    float cirumference() const;
    void draw(Window const& win);


    private:
    float radius_ = 0.0f;
    Vec2 centre_{0.0f,0.0f};
    Color color_{};
};

#endif