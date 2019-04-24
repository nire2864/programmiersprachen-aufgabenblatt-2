#include <iostream>
#include "vec2.hpp"

//Memberfunktionen
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

//Freie Funktionen

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
Vec2 result{u};
result += v;
return result;
};

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
Vec2 result{u};
result -= v;
return result;
}

Vec2 operator * (Vec2 const& v, float s)
{
Vec2 result{v};
result *= s;
return result;
}

Vec2 operator / (Vec2 const& v, float s)
{
if(s == 0) 
    {
    Vec2 result{0, -1};
    std::cout << "Division by zero is undefined.\n";
    return result;
    }   
else
    {
    Vec2 result{v};
    result /= s;
    return result;
    }
}

Vec2 operator * (float s, Vec2 const& v)
{
Vec2 result{v};
result *= s;
return result;
}