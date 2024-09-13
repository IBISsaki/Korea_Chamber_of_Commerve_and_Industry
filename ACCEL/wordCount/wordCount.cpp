#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;
    std::vector<int> counts;

    std::string word;
    while (std::cin >> word)
    {
        std::vector<std::string>::size_type i;
        for (i = 0; i != words.size(); ++i)
        {
            if (word == words[i])
            {
                break;
            }
        }

        if (i == words.size())
        {
            words.push_back(word);
            counts.push_back(1);
        }
        else
        {
            ++counts[i];
        }
    }

    for (std::vector<std::string>::size_type i = 0; i != words.size(); ++i)
    {
        std::cout << words[i] << " : " << counts[i] << std::endl;
    }
    

    return 0;
}
