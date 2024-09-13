#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool isUpper(std::string s)
{
    bool result = false;

    for (std::string::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
        //if (*it >= 'A' && *it <= 'Z') {
        if (isupper(*it)) {
            result = true;
            break;
        }
    }

    return result;
}

int main()
{
    std::vector<std::string> lower, upper;

    std::string s;
    while (std::cin >> s) {
        if (isUpper(s)) {
            upper.push_back(s);
        } else {
            lower.push_back(s);            
        }
    }

    for (std::vector<std::string>::const_iterator it = lower.cbegin(); it != lower.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    for (auto it = upper.cbegin(); it != upper.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}