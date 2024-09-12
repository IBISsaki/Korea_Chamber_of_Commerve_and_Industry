#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums(10);

    for (int i = 1; i <= 10; ++i) {
        int capacity = nums.capacity();

        nums.push_back(i);
    }

    return 0;
}