#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>

// **변경된 부분: Student_info 구조체 수정**
struct Student_info {
    std::string name;       // 학생 이름
    double midterm;         // 중간고사 점수
    double finalterm;       // 기말고사 점수
    double final_grade;     // **최종 점수만 저장**

    Student_info() : midterm(0), finalterm(0), final_grade(0) {}  // 기본 생성자
};

// **변경된 부분: read 함수 시그니처 수정**
std::istream& read(std::istream& in, Student_info& s);

#endif
