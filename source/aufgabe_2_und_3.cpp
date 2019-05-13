#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <time.h>


int main() {

std::list<unsigned int> list_of_random_ints{};
std::set<unsigned int> set_reduced_list{};
srand(time(NULL));

for(int i = 0; i<100; ++i)
{
    unsigned int ran = std::rand()%101;
    list_of_random_ints.push_back(ran);
}

std::copy(std::begin(list_of_random_ints), std::end(list_of_random_ints), std::inserter(set_reduced_list, set_reduced_list.begin()));

for(int i = 0; i<100; ++i)
{
    if(set_reduced_list.count(i) == 0)
    {
        std::cout << i << " is not in the List. \n";
    }
}
//std::copy(std::begin(set_reduced_list),std::end(set_reduced_list), std::ostream_iterator<int>(std::cout, "\n"));
return 0;
}