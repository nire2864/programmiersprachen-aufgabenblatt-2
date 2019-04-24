#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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
  //REQUIRE(first.x == 0.0f);
}

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
  REQUIRE(result2.y == -1.0f);
}

TEST_CASE("Freier operator*(float,Vec2)", "[Vec2]")
{
  Vec2 v{2.4f,3.0f};
  float s = 1.5f;

  Vec2 result = s*v;
  REQUIRE(result.x == Approx(3.6f));
  REQUIRE(result.y == 4.5f);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
