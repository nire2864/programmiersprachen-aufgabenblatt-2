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

TEST_CASE("vector stellenweise addieren", "[Aufgabe12]")
{
    std::vector<int> v_1{1,2,3,4,5,6,7,8,9};
    std::vector<int> v_2{9,8,7,6,5,4,3,2,1};
    std::vector<int> v_3(9);

    std::transform(v_1.begin(),v_1.end(),v_2.begin(),v_3.begin(),[](int i, int j){return i + j;});
    REQUIRE(std::all_of(v_3.begin(),v_3.end() , [](int i){return i == 10;}));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}