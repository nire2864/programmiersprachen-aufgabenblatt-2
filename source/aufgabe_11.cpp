#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <time.h>

bool is_multiple_of_3(int in)
{
    if(in % 3 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool is_not_multiple_of_3(int in)
{
 if(in % 3 == 0);
 return in;   
}



TEST_CASE("filter alle vielfache ovn drei", "[erase]")
{
    std::vector<unsigned int> vector_of_random_ints;
    srand(time(NULL));

    for(int i = 0; i<100; ++i)
    {
        unsigned int ran = std::rand()%101;
        vector_of_random_ints.push_back(ran);
    }

    vector_of_random_ints.erase(std::remove_if(vector_of_random_ints.begin(),vector_of_random_ints.end(),
    is_not_multiple_of_3), vector_of_random_ints.end());
    
    std::copy(std::begin(vector_of_random_ints),std::end(vector_of_random_ints), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;


    REQUIRE(std::all_of(vector_of_random_ints.begin(), vector_of_random_ints.end(), is_multiple_of_3));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}