#include <cstdlib>
#include "rectangle.hpp"

  Rectangle::Rectangle()
    : min_{0.0f, 0.0f}, max_{0.0f, 0.0f}, color_{}
    {}

  Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& col)
    : min_(min), max_(max), color_(col)
    {}
  

float Rectangle::circumference() const
{
  float u = 2*abs(max_.x - min_.x) + 2*abs(max_.y - min_.y);
  return u;
}

void Rectangle::draw(Window const& win)
{
    win.draw_line(max_.x,max_.y,max_.x,min_.y,color_.r,color_.g,color_.b);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,color_.r,color_.g,color_.b);
    win.draw_line(min_.x,min_.y,min_.x,max_.y,color_.r,color_.g,color_.b);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,color_.r,color_.g,color_.b);
}