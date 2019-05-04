#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"

class Rectangle
{
    public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& col);
    
    float circumference() const;
    void draw(Window const& win) const;
    void draw(Window const& win, float thickness) const;
    void draw(Window const& win, float thickness, Color color) const;
    void draw(Window const& win, Color color) const;
    bool is_inside(Vec2 const& point) const;

    private:
    Vec2 min_{0.0f,0.0f};
    Vec2 max_{0.0f,0.0f};
    Color color_;

};

#endif