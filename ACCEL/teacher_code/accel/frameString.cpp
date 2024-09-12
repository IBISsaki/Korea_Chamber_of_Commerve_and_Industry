#include <iostream>
#include <string>

int main()
{
    std::cout << "input your name : ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + "!";

    const std::string firstLine(greeting.size() + 4, '*');
    const std::string secondLine = "* " + std::string(greeting.size(), ' ')+ " *";

    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;
    return 0;
}