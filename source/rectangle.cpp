#include <cstdlib>
#include "rectangle.hpp"

  Rectangle::Rectangle()
    : Min_{0.0f, 0.0f}, Max_{0.0f, 0.0f}, Color_{}
    {}

  Rectangle::Rectangle(Vec2 const& Min, Vec2 const& Max, Color const& Col)
    : Min_(Min), Max_(Max), Color_(Col)
    {}
  

float Rectangle::circumference() const
{
  float u = 2*abs(Max_.x - Min_.x) + 2*abs(Max_.y - Min_.y);
  return u;
}