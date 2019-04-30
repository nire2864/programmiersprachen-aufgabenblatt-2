#include "circle.hpp"

Circle::Circle()
    : radius_{0.0f}, Centre_{0.0f,0.0f}
    {}

Circle::Circle(float radius, Vec2 const& Centre)
    : radius_(radius), Centre_(Centre)
    {}

float Circle::cirumference() const
{
    float u = 2* M_PI * radius_;
    return u;
}