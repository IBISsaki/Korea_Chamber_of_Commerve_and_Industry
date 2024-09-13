#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> words;

    std::ifstream in("lylics.txt");

    std::string word;
    while (in >> word) {
        ++words[word]; 
    }

    for (auto it = words.cbegin(); it != words.cend(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}