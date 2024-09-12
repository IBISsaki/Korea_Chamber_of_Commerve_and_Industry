#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // isspace 함수 사용을 위한 헤더 파일

// 문자열을 공백을 기준으로 나누는 함수
std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : s) {
        if (std::isspace(static_cast<unsigned char>(ch))) {  // 문자가 공백이면
            if (!word.empty()) {  // 현재 단어가 비어 있지 않다면
                words.push_back(word);  // 단어를 벡터에 추가
                word.clear();  // 단어를 초기화
            }
        } else {
            word += ch;  // 문자를 단어에 추가
        }
    }
    if (!word.empty()) {  // 마지막 단어가 비어 있지 않다면
        words.push_back(word);  // 단어를 벡터에 추가
    }

    return words;
}

int main() {
    std::string titleStr;

    // 사용자로부터 문자열 입력 받기
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, titleStr);

    // split 함수 호출
    std::vector<std::string> words = split(titleStr);

    // 각 단어를 한 줄씩 출력
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
