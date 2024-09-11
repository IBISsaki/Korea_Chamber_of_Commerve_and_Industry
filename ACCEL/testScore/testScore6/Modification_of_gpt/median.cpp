#include "median.h"
#include <algorithm>
#include <stdexcept>

// **변경된 부분: 배열을 사용하여 중앙값을 계산**
double median(const double arr[], int size) {
    if (size == 0) {
        throw std::domain_error("Median of an empty array");
    }

    // **변경된 부분: 배열을 복사하여 정렬**
    double* sorted_arr = new double[size];
    std::copy(arr, arr + size, sorted_arr);  // 배열 복사
    std::sort(sorted_arr, sorted_arr + size);  // 배열 정렬

    // **변경된 부분: 중앙값 계산**
    double median_value;
    int mid = size / 2;
    if (size % 2 == 0) {
        median_value = (sorted_arr[mid - 1] + sorted_arr[mid]) / 2;
    } else {
        median_value = sorted_arr[mid];
    }

    delete[] sorted_arr;  // **동적 배열 메모리 해제**

    return median_value;
}
