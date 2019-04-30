#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

//TEST_CASES Vec2 memberfunctions
TEST_CASE("struct Vec2")
{
  Vec2 a;
  Vec2 b{3.1f,8.9f};
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(b.x == 3.1f);
  REQUIRE(b.y == 8.9f);
}

TEST_CASE("Vec2 operator +=" , "[Vec2]")
{
  Vec2 first{1.0,2.0};
  Vec2 second{3.5,3.5};
  
  first += second;
  REQUIRE(first.x == 4.5);
  REQUIRE(first.y == 5.5);
}

TEST_CASE("Vec2 operator -=" , "[Vec2]")
{
  Vec2 first{-1.0,-2.0};
  Vec2 second{3.5,3.5};
  
  first -= second;
  REQUIRE(first.x == -4.5);
  REQUIRE(first.y == -5.5);
}

TEST_CASE("Vec2 operator *=" , "[Vec2]")
{
  Vec2 first{1.0,2.0};
  float s = 3.4f;
  
  first *= s;
  REQUIRE(first.x == 3.4f);
  REQUIRE(first.y == 6.8f);
}

TEST_CASE("Vec2 operator /=" , "[Vec2]")
{
  Vec2 first{1.0,2.0};
  float s = 2.0f;
  float t = 0.0f;
  
  first /= s;
  REQUIRE(first.x == 0.5f);
  REQUIRE(first.y == 1.0f);
  //Division by zero
  first /= t;
}


//TEST_CASES Vec2 freier Funktionen
TEST_CASE("Freier operator+", "[Vec2]")
{
  Vec2 u{3.7f,4.2f};
  Vec2 v{1.3f,2.8f};
  
  Vec2 result = u + v;
  REQUIRE(result.x == 5.0f);
  REQUIRE(result.y == 7.0f);
}

TEST_CASE("Freier operator-", "[Vec2]")
{
  Vec2 u{-1.3f,2.0f};
  Vec2 v{2.3f,4.3f};
  
  Vec2 result = u - v;
  REQUIRE(result.x == Approx(-3.6f));
  REQUIRE(result.y == Approx(-2.3f));
}

TEST_CASE("Freier operator*(Vec2,float)", "[Vec2]")
{
  Vec2 v{2.4f,3.0f};
  float s = 1.5f;

  Vec2 result = v*s;
  REQUIRE(result.x == Approx(3.6f));
  REQUIRE(result.y == 4.5f);
}

TEST_CASE("Freier operator/", "[Vec2]")
{
  Vec2 v{3.5f,2.0f};
  float s = 2;
  float t = 0;

  Vec2 result = v/s;
  REQUIRE(result.x == 1.75f);
  REQUIRE(result.y == 1.0f);

  Vec2 result2 = v/t;
  REQUIRE(result2.x == 0.0f);
  REQUIRE(result2.y == 0.0f);
}

TEST_CASE("Freier operator*(float,Vec2)", "[Vec2]")
{
  Vec2 v{2.4f,3.0f};
  float s = 1.5f;

  Vec2 result = s*v;
  REQUIRE(result.x == Approx(3.6f));
  REQUIRE(result.y == 4.5f);
}

//TEST_CASES matrices
TEST_CASE("Matrix", "[Mat2]")
{
  Mat2 a{};
  Mat2 b{1,2,3,4};

  REQUIRE(a.e_00 == 1);
  REQUIRE(a.e_01 == 0);
  REQUIRE(a.e_10 == 0);
  REQUIRE(a.e_11 == 1);
  REQUIRE(b.e_00 == 1);
  REQUIRE(b.e_01 == 2);
  REQUIRE(b.e_10 == 3);
  REQUIRE(b.e_11 == 4);
}

TEST_CASE("operator*=(Mat2)", "[Mat2]")
{
  Mat2 a{2.0f,2.0f,2.0f,2.0f};
  Mat2 b{3.0f,4.0f,5.0f,6.0f};
 
  a*=b;
  REQUIRE(a.e_00 == 16.0f);
  REQUIRE(a.e_01 == 20.0f);
  REQUIRE(a.e_10 == 16.0f);
  REQUIRE(a.e_11 == 20.0f);
}

TEST_CASE("Freier operator*(Mat2,Mat2)", "[Mat2]")
{
  Mat2 a{2.0f,2.0f,2.0f,2.0f};
  Mat2 b{3.0f,4.0f,5.0f,6.0f};

  Mat2 result = a * b;
  REQUIRE(result.e_00 == 16.0f);
  REQUIRE(result.e_01 == 20.0f);
  REQUIRE(result.e_10 == 16.0f);
  REQUIRE(result.e_11 == 20.0f);
}

TEST_CASE("Freier operator*(Mat2,Vec2)","[Mat2]")
{
  Mat2 m{1.0f,2.0f,3.0f,4.0f};
  Vec2 v{5.0f,6.0f};

  Vec2 result = m*v;
  REQUIRE(result.x == 17);
  REQUIRE(result.y == 39);
}

TEST_CASE("Freier operator*(Vec2,Mat2)","[Mat2]")
{
  Mat2 m{1.0f,2.0f,3.0f,4.0f};
  Vec2 v{5.0f,6.0f};

  Vec2 result = v*m;
  REQUIRE(result.x == 17); 
  REQUIRE(result.y == 39);
}

TEST_CASE("operator*=(float)", "[Mat2]")
{
  Mat2 m{2.0f,3.0f,4.0f,5.0f};
  float lambda = 2.0f;

  m*=lambda;
  REQUIRE(m.e_00 == 4.0f);
  REQUIRE(m.e_01 == 6.0f);
  REQUIRE(m.e_10 == 8.0f);
  REQUIRE(m.e_11 == 10.0f);
}

TEST_CASE("freier operator*=(float, Mat2)", "[Mat2]")
{
  Mat2 m{2.0f,3.0f,4.0f,5.0f};
  float lambda = 2.0f;

  Mat2 result = lambda*m;
  REQUIRE(result.e_00 == 4.0f);
  REQUIRE(result.e_01 == 6.0f);
  REQUIRE(result.e_10 == 8.0f);
  REQUIRE(result.e_11 == 10.0f);
}

TEST_CASE("freier operator*=(Mat2, float)", "[Mat2]")
{
  Mat2 m{2.0f,3.0f,4.0f,5.0f};
  float lambda = 2.0f;

  Mat2 result = m*lambda;
  REQUIRE(result.e_00 == 4.0f);
  REQUIRE(result.e_01 == 6.0f);
  REQUIRE(result.e_10 == 8.0f);
  REQUIRE(result.e_11 == 10.0f);
}

TEST_CASE("Determinante", "[Mat2]")
{
  Mat2 a{1.0f,2.0f,3.0f,4.0f};
  
  float s = a.det();
  REQUIRE(s == -2);
}

TEST_CASE("inverse(Mat2)", "[Mat2]")
{
  Mat2 m{1.0f,2.0f,3.0f,4.0f};
  
  Mat2 result = inverse(m);
  REQUIRE(result.e_00 == -2.0f);
  REQUIRE(result.e_01 == 1.0f);
  REQUIRE(result.e_10 == 1.5f);
  REQUIRE(result.e_11 == -0.5f);
}

TEST_CASE("transpose(Mat2)", "[Mat2]")
{
  Mat2 m{1.0f,2.0f,3.0f,4.0f};
  
  Mat2 result = transpose(m);
  REQUIRE(result.e_00 == 1.0f);
  REQUIRE(result.e_01 == 3.0f);
  REQUIRE(result.e_10 == 2.0f);
  REQUIRE(result.e_11 == 4.0f);

}

TEST_CASE("make_rotation_mat2(float phi)", "[Mat2]")
{
  float phi = 0.5f * M_PI;

  Mat2 result = make_rotation_mat2(phi);
  REQUIRE(result.e_00 == Approx(0.0f));
  REQUIRE(result.e_01 == -1.0f);
  REQUIRE(result.e_10 == 1.0f);
  REQUIRE(result.e_11 == Approx(0.0f));
}

//TEST_CASES Color
TEST_CASE("color", "[Color]")
{
  Color standard{};
  Color pink{1.0f,0.0f,1.0f};

  REQUIRE(standard.r == 0.5f);
  REQUIRE(standard.g == 0.5f);
  REQUIRE(standard.b == 0.5f);
  REQUIRE(pink.r == 1.0f);
  REQUIRE(pink.g == 0.0f);
  REQUIRE(pink.b == 1.0f);
}

//Rectangele & Circle circumference
TEST_CASE("circumference rectangle","[Rectangle]")
{
  Rectangle rechteck{{-2.0f,4.0f},{10.0f,14.0f}};

  auto result = rechteck.circumference();
  REQUIRE(result == 44.0f);
}

TEST_CASE("circumference circle", "[Circle]")
{
  Circle kreis{14,{14.0f,14.0f}};

  auto result = kreis.cirumference();
  REQUIRE(result == Approx(87.965f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
