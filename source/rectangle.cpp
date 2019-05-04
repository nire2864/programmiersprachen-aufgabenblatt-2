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

void Rectangle::draw(Window const& win) const
{
    win.draw_line(max_.x,max_.y,max_.x,min_.y,color_.r,color_.g,color_.b);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,color_.r,color_.g,color_.b);
    win.draw_line(min_.x,min_.y,min_.x,max_.y,color_.r,color_.g,color_.b);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,color_.r,color_.g,color_.b);
}

void Rectangle::draw(Window const& win, float thickness) const
{
    win.draw_line(max_.x,max_.y,max_.x,min_.y,color_.r,color_.g,color_.b, thickness);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,color_.r,color_.g,color_.b, thickness);
    win.draw_line(min_.x,min_.y,min_.x,max_.y,color_.r,color_.g,color_.b, thickness);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,color_.r,color_.g,color_.b, thickness);
}

void Rectangle::draw(Window const& win, float thickness, Color color) const
{
    win.draw_line(max_.x,max_.y,max_.x,min_.y,color.r,color.g,color.b, thickness);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,color.r,color.g,color.b, thickness);
    win.draw_line(min_.x,min_.y,min_.x,max_.y,color.r,color.g,color.b, thickness);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,color.r,color.g,color.b, thickness);
}

void Rectangle::draw(Window const& win, Color color) const
{
    win.draw_line(max_.x,max_.y,max_.x,min_.y,color.r,color.g,color.b);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,color.r,color.g,color.b);
    win.draw_line(min_.x,min_.y,min_.x,max_.y,color.r,color.g,color.b);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,color.r,color.g,color.b);
}

bool Rectangle::is_inside(Vec2 const& point) const
{
    if(point.x <= max_.x && point.y <= max_.y && point.x >= min_.x && point.y >= min_.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}