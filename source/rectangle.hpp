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
    void draw(Window const& win);

    private:
    Vec2 min_{0.0f,0.0f};
    Vec2 max_{0.0f,0.0f};
    Color color_;

};

#endif