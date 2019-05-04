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
    void draw(Window const& win) const;
    void draw(Window const& win, float thickness) const;
    void draw(Window const& win, float thickness, Color color) const;
    void draw(Window const& win, Color color) const;
    bool is_inside(Vec2 const& point) const;

    private:
    float radius_ = 0.0f;
    Vec2 centre_{0.0f,0.0f};
    Color color_{};
};

#endif