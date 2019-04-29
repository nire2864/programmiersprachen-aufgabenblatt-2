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