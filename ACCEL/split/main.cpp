#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> split(const std::string& s)
{
    std::vector<std::string> words;

    std::string::size_type i = 0;
    while(i != s.size()) {
        while (i != s.size() && isspace(s[i]) ) {
            ++i;
        }

        std::string::size_type j = i;
        while (j != s.size() && !isspace(s[j]) ) {
            ++j;
        }
        
        if(i != j) {
            words.push_back(s.substr(i, j-i));
            i = j;
        }
    }

    return words;
}


int main()
{
    // const std::string title = "just the way you are";
    // std::vector<std::string> words = split(title);
    std::vector<std::string> words;
    std::string s;
    while (std::getline(std::cin, s)) {
        words = split(s);
    }
    

    for (auto it = words.cbegin(); it != words.cend(); ++it) {
        std::cout << *it << std::endl;
    }
    

    return 0;
}