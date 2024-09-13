#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> vec = {3, 1, 2, 3, 4, 3, 3, 5};

    std::vector<int>::iterator it = remove(vec.begin(), vec.end(), 3);
    vec.erase(it, vec.end());

    copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}