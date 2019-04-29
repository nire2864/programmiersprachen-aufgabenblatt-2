#include <iostream>
#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m)
{
  auto a = e_00;
  auto b = e_01;
  auto c = e_10;
  auto d = e_11;

  e_00 = a * m.e_00 + b * m.e_10;
  e_01 = a * m.e_01 + b * m.e_11;
  e_10 = c * m.e_00 + d * m.e_10;
  e_11 = c * m.e_01 + d * m.e_11;

  return *this; 
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
    Mat2 result{m1};
    result *= m2;
    return result;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
  auto a = v.x;
  auto b = v.y;

  Vec2 result{m.e_00 * a + m.e_01 * b,
  m.e_10 * a + m.e_11 * b};

  return result;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m)
{
  auto a = v.x;
  auto b = v.y;

  Vec2 result{m.e_00 * a + m.e_01 * b,
  m.e_10 * a + m.e_11 * b};

  return result;
}

float Mat2::det() const
{
  float result = e_00 * e_11 - e_10 * e_01;
  return result;
}

Mat2& Mat2::operator*=(float lambda)
{
  e_00*=lambda;
  e_01*=lambda;
  e_10*=lambda;
  e_11*=lambda;
  
  return *this;
}

Mat2 operator*(float lambda, Mat2 const& m)
{
  Mat2 result{m};
  result *= lambda;
  return result;
}

Mat2 operator*(Mat2 const& m,float lambda)
{
  Mat2 result{m};
  result *= lambda;
  return result;
}

Mat2 inverse(Mat2 const& m)
{
  Mat2 n{m.e_11,-m.e_01,-m.e_10,m.e_00};
  Mat2 result = 1/(m.det())*n;
  return result;
}

Mat2 transpose(Mat2 const& m)
{
  Mat2 result{m.e_00,m.e_10,m.e_01,m.e_11};
  return result;
}