#include <iostream>
#include <algorithm>
#include <ios>
#include <vector>
#include <iomanip>
#include <string>

int main()
{
    std::cout << "input name : ";
    std::string name;
    std::cin >> name;

    std::cout << "input midtrem finalterm : ";
    double midtermm, finalterm;
    std::cin >> midtermm >> finalterm;

    std::vector<double> homeworks;
    double homework;
    while (std::cin >> homework)
    {
        homeworks.push_back(homework);
    }
    
    if (homeworks.size() == 0)  
    {
        std::cerr << "try input homework again" << std::endl;
        return 1;
    }
    
    std::sort(homeworks.begin(), homeworks.end());

    std::vector<double>::size_type mid = homeworks.size() / 2;    
    
    double median;
    if (homeworks.size() % 2 ) {
        median = homeworks[mid];
    } else {
        median = (homeworks[mid] + homeworks[mid - 1]) / 2;
    }
    
    const double finalScore = 0.2 * midtermm + 0.4 * finalterm + 0.4 * median;

    std::streamsize prec = std::cout.precision();
    std::cout << "Your final score : " << std::setprecision(3) << finalScore 
                    << std::setprecision(prec) << std::endl;


    return 0;
}