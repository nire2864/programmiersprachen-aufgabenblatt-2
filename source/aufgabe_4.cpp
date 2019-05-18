#include "circle.hpp"
#include <iostream>
#include <ostream>

int main() {
Circle circle1{23.0f,{25.0f,30.0f},{},"Hans"};
Circle circle2{20.0f,{15.0f,4.0f},{0.33f,0.22f,0.33f},"Peter"};
Circle circle3{3.0f,{10.0f,30.0f},{1.0f,0.0f,1.0f},"Otto"};
Circle circle4{23.0f,{25.0f,30.0f},{0.0f,1.0f,0.0f},"Ferdinant"};



std::cout << circle1 << circle2 << circle3 << circle4 << std::endl;
return 0;
}
