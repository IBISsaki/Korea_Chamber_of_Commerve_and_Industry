#include "student_info.h"
#include "grade.h"
#include <iostream>

// **변경된 부분: read 함수 정의**
std::istream& read(std::istream& in, Student_info& s) {
    // 기본 정보 입력
    std::cout << "Enter name, midterm, finalterm: ";
    in >> s.name >> s.midterm >> s.finalterm;

    // **변경된 부분: 숙제 점수를 위한 고정 크기 배열 사용**
    const int MAX_HOMEWORKS = 10;  // **숙제 점수의 최대 개수**
    double homeworks[MAX_HOMEWORKS];
    int count = 0;

    // **변경된 부분: 숙제 점수 배열에 저장**
    std::cout << "Enter homework grades (enter non-number to end): ";
    double homework;
    while (count < MAX_HOMEWORKS && in >> homework) {  // 최대 10개의 점수까지 입력받음
        homeworks[count++] = homework;
    }
    in.clear();  // 입력 스트림 상태를 초기화합니다.

    // **변경된 부분: 최종 점수 계산 후 저장**
    s.final_grade = grade(s.midterm, s.finalterm, homeworks, count);
    
    return in;
}
