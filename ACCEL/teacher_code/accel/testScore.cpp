#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

int main()
{
    std::cout << "input name : ";
    std::string name;
    std::cin >> name;

    std::cout << "input midterm finalterm : ";
    double midterm, finalterm;
    std::cin >> midterm >> finalterm;

    int count = 0;
    double sum = 0;
    double homework;
    while (std::cin >> homework) {
        sum += homework;
        ++count;
    }

    const double finalScore = 0.2 * midterm + 0.4 * finalterm + 0.4 * sum / count; 
    
    std::streamsize prec = std::cout.precision();
    std::cout << "Your final score : " << std::setprecision(3) << finalScore 
                    << std::setprecision(prec) << std::endl;


    return 0;
}