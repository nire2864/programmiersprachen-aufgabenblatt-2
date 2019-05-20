#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <vector>

template<typename function, typename T, template<typename, typename = std::allocator<T>> class Container> 
Container<T> filter(Container<T> const& container_in, function f){
    Container<T> container_out(container_in.size());
    for(auto element : container_in) {
        if(f(element))
        {
            container_out.emplace_back(element);
        }
    }
    return container_out;
}

bool is_even(int n){return n % 2 == 0;};

TEST_CASE("Aufgabe 13")
{
std::vector<int> vector_of_random_ints{};
srand(time(NULL));

for(int i = 0; i<100; ++i)
{
    int ran = std::rand()%101;
    vector_of_random_ints.push_back(ran);
}

std::vector<int> vector_of_even_randoms = filter(vector_of_random_ints,[](int number) -> bool {
    if(number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
});
REQUIRE(std::all_of(vector_of_even_randoms.begin(),vector_of_even_randoms.end(), is_even));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}