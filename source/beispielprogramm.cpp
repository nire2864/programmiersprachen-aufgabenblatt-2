#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    /*
        Fülle den Vector v_0 mit 10 Zufallszahlen
    */
    std::vector<int> v_0(10);

    for (auto& v: v_0)
    {
        v = std::rand();
    }

    /*
    Vector ausgeben (in ein ostream-objekt koperien und dann ausgeben)
   */
    std::copy(std::cbegin(v_0), std::cend(v_0),
    std::ostream_iterator<int>(std::cout, "\n"));


    /*
    Übertragen von v_0 in die Listen l_0 und l_1
   */
    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));
    
    /*
    l_1 wird umgedreht und danach wie oben ausgegeben
   */
    std::reverse(std::begin(l_1), std::end(l_1));
    std::copy(std::cbegin(l_1), std::cend(l_1),
    std::ostream_iterator<int>(std::cout, "\n"));

    /*
    l_1 wird sortiert und dananach ausgegeben
   */
    l_1.sort();
    std::copy(l_1.cbegin(), l_1.cend(),
    std::ostream_iterator<int>(std::cout, "\n"));

    /*
    V_0 werden neue Zufallszahlen zugewiesen und dann ausgegeben
   */
    std::generate(std::begin(v_0), std::end(v_0), std::rand);
    std::copy(v_0.crbegin(), v_0.crend(),
    std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}