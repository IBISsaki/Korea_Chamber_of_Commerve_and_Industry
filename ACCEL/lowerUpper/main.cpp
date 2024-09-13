#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // std::isspace(), std::isupper() 사용을 위해 필요

// 대문자가 하나라도 포함되어 있는지 확인하는 함수
bool isUpper(std::string s) {
    bool result = false;
    for (std::string::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
        // if (*it >= 'A' && *it <= 'Z') {  // 문자가 대문자인지 확인
        if(isupper(*it)) {
            result = true;
            break;
        }
    }
    return result;
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
    for (std::vector<std::string>::const_iterator it = lower.cbegin(); it != lower.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    // 대문자가 하나 이상 포함된 단어들 출력
    std::cout << "대문자 있음 :\n";
    for (auto it = upper.cbegin(); it != upper.cend(); ++it) {
        std::cout << *it << std::endl;
    }
    

    return 0;
}
