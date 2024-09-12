#ifndef GRADE_H
#define GRADE_H
#include <vector>
#include "student_info.h"

double grade(double mid, double final, double hw);
double grade(double mid, double final, const std::vector<double>& homeworks);
double grade(const Student_info& s);

#endif