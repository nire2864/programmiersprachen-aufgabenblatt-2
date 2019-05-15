#include <iostream>
#include <list>
#include <set>
#include <map>
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


std::cout << "The following numbers are not in the list: \n";
for(int i = 0; i<100; ++i)
{
    if(set_reduced_list.count(i) == 0)
    {
        std::cout << "[" << i << "] ";
    }
}
//std::copy(std::begin(set_reduced_list),std::end(set_reduced_list), std::ostream_iterator<int>(std::cout, "\n"));

std::map<unsigned int, unsigned int> map_occurence;

for(auto element : list_of_random_ints)
{
    map_occurence[element]++;       //Referenz auf den Wert, welcher durch den Index adressiert wird wird um eins erhöht.
}                                   //Default initialization for ints = 0


std::cout << "\n" << "The absolute frequencies(f) of random numbers x in [0,100] will be printed as [x:f]."
<<"\nEvery unlisted number has not been created by the random generator. Thus, their frequency is 0.\n";
for(auto element : map_occurence)
{
    std::cout << "[" <<element.first << ":" << element.second << "]  "; 
}
std::cout << "\n";


return 0;
}
