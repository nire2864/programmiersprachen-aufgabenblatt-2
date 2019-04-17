#include "vec2.hpp"

Vec2& Vec2::operator +=(Vec2 const& v) 
{
y += v.y;
x += v.x;
return *this;
};

Vec2& Vec2::operator -=(Vec2 const& v) 
{
    y -= v.y;
    x -= v.x;
    return *this;
};

Vec2& Vec2::operator *=(float s)
 {
     y *= s;
     x *= s;
     return *this;
 };

Vec2& Vec2::operator /=(float s)
 {
     y /= s;
     x /= s;
     return *this;
 };
