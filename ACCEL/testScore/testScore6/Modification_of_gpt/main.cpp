#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ios>
#include <iomanip>
#include "student_info.h"
#include "grade.h"

// **수정되지 않은 부분: 비교 함수**
bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name < s2.name;
}

// **수정되지 않은 부분: main 함수**
int main() {
    std::vector<Student_info> students;  // 학생 정보 저장 벡터
    std::string::size_type maxLen = 0;   // 가장 긴 이름 길이를 저장
    Student_info s;

    // 학생 정보 입력 반복
    while (read(std::cin, s)) {
        students.push_back(s);
        maxLen = std::max(maxLen, s.name.size());  // 가장 긴 이름 길이 업데이트
    }
    
    // 이름 기준 정렬
    std::sort(students.begin(), students.end(), compare);

    // **변경된 부분: 최종 점수 출력**
    for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        std::streamsize prec = std::cout.precision();
        std::cout << students[i].name 
            << std::string(maxLen - students[i].name.size() + 1, ' ')
            << std::setprecision(3) << students[i].final_grade  // **최종 점수 사용**
            << std::setprecision(prec) << std::endl;
    }

    return 0;
}
