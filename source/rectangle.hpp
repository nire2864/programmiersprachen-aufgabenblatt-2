#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include <math.h>
#include "color.hpp"
#include "vec2.hpp"

class Rectangle
{
    public:
    Rectangle();
    Rectangle(Vec2 const& Min, Vec2 const& Max);
    
    float circumference() const;

    private:
    Vec2 Min_{0.0f,0.0f};
    Vec2 Max_{0.0f,0.0f};

};

#endif