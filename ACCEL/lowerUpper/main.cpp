#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // std::isspace(), std::isupper() 사용을 위해 필요

// 대문자가 하나라도 포함되어 있는지 확인하는 함수
bool isUpper(const std::string& s) {
    for (char c : s) {
        if (std::isupper(c)) {  // 문자가 대문자인지 확인
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::string> lower, upper;
    std::string s;

    // 사용자로부터 단어 입력받기
    while (std::cin >> s) {
        if (isUpper(s)) {
            upper.push_back(s);  // 대문자가 포함된 단어는 upper 벡터에 추가
        } else {
            lower.push_back(s);  // 대문자가 없는 단어는 lower 벡터에 추가
        }
    }

    // 대문자가 없는 단어들 출력
    std::cout << "대문자 없음 :\n";
    for (const auto& word : lower) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // 대문자가 하나 이상 포함된 단어들 출력
    std::cout << "대문자 있음 :\n";
    for (const auto& word : upper) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
