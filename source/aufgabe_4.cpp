#include "circle.hpp"
#include <iostream>
#include <ostream>
#include <map>
#include <set>



int main() {
Circle circle1{23.0f,{25.0f,30.0f},{},"Hans"};
Circle circle2{20.0f,{15.0f,4.0f},{0.33f,0.22f,0.33f},"Peter"};
Circle circle3{3.0f,{10.0f,30.0f},{1.0f,0.0f,1.0f},"Otto"};
Circle circle4{23.0f,{25.0f,30.0f},{0.0f,1.0f,0.0f},"Ferdinant"};
Circle circle5{23.5f,{25.3f,30.9f},{0.34f,1.0f,0.0f},"Ferdinant"};
std::set<Circle> circles;
std::string name;

std::cout << circle1 << circle2 << circle3 << circle4 << std::endl;


circles.insert(circle1);
circles.insert(circle2);
circles.insert(circle3);
circles.insert(circle4);
circles.insert(circle5);

std::cout << "Please insert the name you are searching for: " << std::endl;
std::cin >> name;

bool check = false;
for(Circle ci : circles)
{
    std::string name_of_element = ci.getName();
    if(name_of_element == name)
    {
        std::cout << ci << std::endl;
        check = true;
        break;
    }
}
if(check == false)
{
    std::cout << "The circle you are searching for does not exist." << std::endl;
}
return 0;
}
