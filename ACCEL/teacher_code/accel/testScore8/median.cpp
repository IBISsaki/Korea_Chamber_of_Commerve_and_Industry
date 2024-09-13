#include <vector>
#include <algorithm>
#include "median.h"

double median(const std::vector<double>& vec)
{
    //std::vector<double> vec2(list.cbegin(), list.cend());
    std::vector<double> vec2 = vec;

    std::sort(vec2.begin(), vec2.end());

    const std::vector<double>::size_type mid = vec2.size() / 2;

    double median;
    if (vec2.size() % 2 ) {
        median = vec2[mid];
    } else {
        median = (vec2[mid] + vec2[mid-1]) / 2;
    }
    return median;
}