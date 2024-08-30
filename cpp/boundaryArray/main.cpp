#include <iostream>
#include "boundaryArray.h"
#include "complex.h"

int main()
{
    BoundaryArray<int> arr3;
    BoundaryArray<int> arr4(10);
    int nums [] = {1, 2, 3, 4, 5};
    BoundaryArray<int> arr5(nums, 5, 1);
    BoundaryArray<int> arr6 = arr5;

    arr3 = arr5;

    if(arr3 == arr5) {
        std::cout << "arr3 and arr5 are equal" << std::endl;
    } else {
        std::cout << "arr3 and arr5 are not equal" << std::endl;
    }

    BoundaryArray<int> arr1(1, 5);
    for(int i = arr1.lower(); i <= arr1.upper(); ++i) {
        arr1[i] = i;
    }

    for(int i = arr1.lower(); i <= arr1.upper(); ++i) {
        std::cout << arr1[i] << std::endl;
    }

    BoundaryArray<Complex> arr2(11, 15);       
    for(int i = arr2.lower(); i <= arr2.upper(); ++i) {
        arr2[i] = Complex(i);
    }

    for(int i = arr2.lower(); i <= arr2.upper(); ++i) {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}