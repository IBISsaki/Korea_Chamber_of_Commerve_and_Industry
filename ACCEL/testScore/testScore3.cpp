#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <vector>
#include <iomanip>
#include <string>

std::istream& read_hw(std::istream& in, std::vector<double>& homeworks)
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

double median(const std::vector<double>& vec)
{
    std::vector<double> vec2 =vec;
    std::sort(vec2.begin(), vec2.end());

    const std::vector<double>::size_type mid = vec2.size() / 2;

    double median;
    if (vec2.size() % 2 ) {
        median = vec2[mid];
    } else {
        median = (vec2[mid] + vec2[mid - 1]) / 2;
    }
    return median;
}

double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const std::vector<double>& homeworks)
{
    if (homeworks.size() == 0)
    {
        throw std::domain_error("no homework");
    }
    double median = ::median(homeworks);

    return grade(midterm, finalterm, median);
}

int main()
{
    std::cout << "input name : ";
    std::string name;
    std::cin >> name;

    std::cout << "input midterm finalterm : ";
    double midterm, finalterm;
    std::cin >> midterm >> finalterm;

    std::vector<double> homeworks;
    read_hw(std::cin, homeworks);
    
    try
    {
    const double finalScore = grade(midterm, finalterm, homeworks);

    std::streamsize prec = std::cout.precision();
    std::cout << "Your final score : " << std::setprecision(3) << finalScore 
                    << std::setprecision(prec) << std::endl;
    }   catch(const std::domain_error& e)   {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    

   
    return 0;
}