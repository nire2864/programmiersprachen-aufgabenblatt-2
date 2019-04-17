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
  
  first /= s;
  REQUIRE(first.x == 0.5f);
  REQUIRE(first.y == 1.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
