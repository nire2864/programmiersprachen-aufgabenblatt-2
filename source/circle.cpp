#include <math.h>
#include <iostream>
#include <ostream>
#include "circle.hpp"
#include "mat2.hpp"


Circle::Circle()
    : radius_{0.0f}, centre_{0.0f,0.0f}, color_{}
    {}

Circle::Circle(float radius, Vec2 const& centre, Color const& col)
    : radius_(radius), centre_(centre), color_(col)
    {}

Circle::Circle(float radius, Vec2 const& centre, Color const& col, std::string const& name)
    : radius_(radius), centre_(centre), color_(col), name_(name)
    {}


float Circle::cirumference() const
{
    float u = 2* M_PI * radius_;
    return u;
}

void Circle::draw(Window const& win) const
{
    Vec2 start_point{centre_.x,centre_.y + radius_};
    Vec2  end_point = start_point;
    Mat2 rotation_mat = make_rotation_mat2((2* M_PI)/360);
    for(int i = 1; i < 361; ++i)
    {
      Vec2 next_point = centre_ + (rotation_mat * (end_point - centre_));
      win.draw_line(end_point.x,end_point.y,
                    next_point.x,next_point.y,
                    color_.r,color_.g,color_.b);
      end_point = next_point;
    }
}

void Circle::draw(Window const& win, float thickness) const
{
    Vec2 start_point{centre_.x,centre_.y + radius_};
    Vec2  end_point = start_point;
    Mat2 rotation_mat = make_rotation_mat2((2* M_PI)/360);
    for(int i = 1; i < 361; ++i)
    {
      Vec2 next_point = centre_ + (rotation_mat * (end_point - centre_));
      win.draw_line(end_point.x,end_point.y,
                    next_point.x,next_point.y,
                    color_.r,color_.g,color_.b,
                    thickness);
      end_point = next_point;
    }
}

void Circle::draw(Window const& win, float thickness, Color color) const
{
    Vec2 start_point{centre_.x,centre_.y + radius_};
    Vec2  end_point = start_point;
    Mat2 rotation_mat = make_rotation_mat2((2* M_PI)/360);
    for(int i = 1; i < 361; ++i)
    {
      Vec2 next_point = centre_ + (rotation_mat * (end_point - centre_));
      win.draw_line(end_point.x,end_point.y,
                    next_point.x,next_point.y,
                    color.r,color.g,color.b,
                    thickness);
      end_point = next_point;
    }
}

void Circle::draw(Window const& win, Color const& color) const
{
    Vec2 start_point{centre_.x,centre_.y + radius_};
    Vec2  end_point = start_point;
    Mat2 rotation_mat = make_rotation_mat2((2* M_PI)/360);
    for(int i = 1; i < 361; ++i)
    {
      Vec2 next_point = centre_ + (rotation_mat * (end_point - centre_));
      win.draw_line(end_point.x,end_point.y,
                    next_point.x,next_point.y,
                    color.r,color.g,color.b);
      end_point = next_point;
    }
}

bool Circle::is_inside(Vec2 const& point) const
{
    Vec2 vec_to_centre = centre_ - point; //Vec2 PQ = P - Q
    float distance_to_centre = sqrt(pow(vec_to_centre.x,2)+ pow(vec_to_centre.y,2)); 
    if(distance_to_centre < radius_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& Circle::print(std::ostream& os) const
{
    os << "[" << name_ << ";{" << centre_.x << "," << centre_.y <<"};"<< radius_ <<";{"<< color_.r << "," << color_.g << "," << color_.b <<"}]";
    return os;
}

std::ostream& operator<<(std::ostream& os, Circle const& circle) 
{
   return circle.print(os);
}