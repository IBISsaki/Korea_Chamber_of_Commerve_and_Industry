#include "grade.h"
#include <stdexcept>
#include <algorithm>

// **변경된 부분: 배열을 사용하여 중앙값을 계산**
double grade(double midterm, double finalterm, const double homeworks[], int count) {
    if (count == 0) {
        throw std::domain_error("No homework grades provided.");
    }

    // **변경된 부분: 배열을 복사하여 정렬**
    double* sorted_homeworks = new double[count];
    std::copy(homeworks, homeworks + count, sorted_homeworks);  // 배열 복사
    std::sort(sorted_homeworks, sorted_homeworks + count);  // 배열 정렬

    // **변경된 부분: 중앙값 계산**
    double median;
    int mid = count / 2;
    if (count % 2 == 0) {
        median = (sorted_homeworks[mid - 1] + sorted_homeworks[mid]) / 2;
    } else {
        median = sorted_homeworks[mid];
    }

    delete[] sorted_homeworks;  // **동적 배열 메모리 해제**

    return 0.2 * midterm + 0.4 * finalterm + 0.4 * median;  // **최종 점수 계산**
}
