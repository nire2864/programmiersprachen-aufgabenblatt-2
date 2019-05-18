#include "circle.hpp"
#include <iostream>
#include <vector>
#include <catch.hpp>


#include <algorithm>

int main()
{
    Circle circle1{23.0f,{25.0f,30.0f},{},"Hans"};
    Circle circle2{20.0f,{15.0f,4.0f},{0.33f,0.22f,0.33f},"Peter"};
    Circle circle3{3.0f,{10.0f,30.0f},{1.0f,0.0f,1.0f},"Otto"};
    Circle circle4{23.0f,{25.0f,30.0f},{0.0f,1.0f,0.0f},"Ferdinant"};
    Circle circle5{23.5f,{25.3f,30.9f},{0.34f,1.0f,0.0f},"Ferdinant"};
 
    std::vector<Circle> sorted_circles;
    sorted_circles.push_back(circle1);
    sorted_circles.push_back(circle2);
    sorted_circles.push_back(circle3);
    sorted_circles.push_back(circle4);
    sorted_circles.push_back(circle5);
    std::sort(sorted_circles.begin(),sorted_circles.end());
    //REQUIRE(std::is_sorted(sorted_circles.begin(),sorted_circles.end()));

    std::sort(sorted_circles.begin(),sorted_circles.end(),
    [](Circle const& first, Circle const& second) -> bool {
        return (first > second);
    });
    
    for(Circle circle : sorted_circles)
    {
        std::cout << circle << std::endl; 
    }

    return 0;
}