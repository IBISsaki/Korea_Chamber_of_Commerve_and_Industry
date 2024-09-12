#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <ios>
#include <iomanip>
#include "student_info.h"
#include "grade.h"
#include "median.h"


bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}


int main()
{
    std::vector<Student_info> students;

    // int maxLen = 0;
    std::string::size_type maxLen = 0;
    try
    {    
        Student_info s;
        while (read(std::cin, s))
        {
            students.push_back(s);
        
            // if(maxLen < s.name.size())
            // {
            //     maxLen = s.name.size();
            // }
            maxLen = std::max(maxLen, s.name.size());
        }
    } catch(const std::domain_error& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::sort(students.begin(), students.end(), compare);


    for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        const double finalScore = grade(students[i]);

        std::streamsize prec = std::cout.precision();
        std::cout << students[i].name 
            << std::string(maxLen - students[i].name.size() + 1, ' ')
            << std::setprecision(3) << finalScore 
            << std::setprecision(prec) << std::endl;
    
    }
    
    return 0;
}