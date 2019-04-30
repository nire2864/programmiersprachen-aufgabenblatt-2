#include "circle.hpp"

Circle::Circle()
    : radius_{0.0f}, Centre_{0.0f,0.0f}, Color_{}
    {}

Circle::Circle(float radius, Vec2 const& Centre, Color const& Col)
    : radius_(radius), Centre_(Centre), Color_(Col)
    {}

float Circle::cirumference() const
{
    float u = 2* M_PI * radius_;
    return u;
}