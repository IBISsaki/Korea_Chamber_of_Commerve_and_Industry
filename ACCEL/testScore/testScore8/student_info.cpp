#include "student_info.h"

static std::istream& read_hw(std::istream& in, std::vector<double>& homeworks)
{
    if(in) 
    {
        homeworks.clear();
        
        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }
        
        in.clear();
    }

    return in;
}

std::istream& read(std::istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homeworks);

    return in;
}