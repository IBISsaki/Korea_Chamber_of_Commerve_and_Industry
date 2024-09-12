#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <iostream>
#include <vector>
#include <string>


struct Student_info {
    std::string name;
    double midterm;
    double finalterm;
    std::vector<double> homeworks;
};

static std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);

std::istream& read(std::istream& in, Student_info& s);

#endif