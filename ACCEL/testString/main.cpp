#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

string::size_type width(const vector<string>& v)
{
    string::size_type maxLen = 0;
    for(auto it = v.cbegin(); it != v.cend(); ++it){
        // if(maxLen < it -> size()) {
        //     maxLen = it -> size();
        // }
        maxLen = std::max(maxLen, it -> size());
    }
    return maxLen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> result;

    string::size_type maxLen = width(v);
    string boarder(maxLen + 4, '*');

    result.push_back(boarder);

    for(auto it = v.begin(); it != v.cend(); ++it) {
        string s = "*" + *it + string(maxLen - it -> size(), ' ') + " *";
        result.push_back(s);
    }

    result.push_back(boarder);

    return result;
}

vector<string> vertical_cat(const vector<string>& v1, const vector<string>& v2)
{
    vector<string> result;
    result = v1;
    // for(auto it = v2.cbegin(); it != v2.cend(); ++it) {
    //     result.push_back(*it);
    // }
    result.insert(result.cend(), v2.cbegin(), v2.cend());

    return result;
}

// 수평으로 문자열 벡터를 연결하는 함수
vector<string> horizontal_cat(const vector<string>& v1, const vector<string>& v2) {
    vector<string> result;

    string::size_type width1 = width(v1);

    // iterator를 사용하여 v1과 v2 순회
    vector<string>::const_iterator it1 = v1.cbegin();
    auto it2 = v2.cbegin();

    while (it1 != v1.cend() || it2 != v2.cend()) {
        string s;

        // v1의 문자열을 결과 문자열에 추가
        if (it1 != v1.cend()) {
            s = *it1;
            ++it1;
        }

        // 너비 조정 후 공백 추가
        s = s + string(width1 - s.size() + 1, ' ');

        // v2의 문자열을 결과 문자열에 추가
        if (it2 != v2.cend()) {
            s = s + *it2;
            ++it2;
        }

        // 결과 벡터에 문자열 추가
        result.push_back(s);
    }

    return result;
}

// vector<string> horizontal_cat(const vector<string>& v1, const vector<string>& v2)
// {
//     vector<string> result;

//     string::size_type width1 = width(v1);

    
//     int i = 0, j = 0;
//     while (i != v1.size() || j != v2.size()) {
//         string s;

//         if (i != v1.size()) {
//             s = v1[i];
//             ++i;
//         } 
//         s = s + string(width1 - s.size() + 1, ' ');

//         if (j != v2.size())
//         {
//             s = s + v2[i];
//             ++j;
//         }
        
        

//         result.push_back(s);
//     }
    
//     return result;
// }

int main()
{
    vector<string> lines;
    lines.push_back("this is an");
    lines.push_back("example");
    lines.push_back("to");
    lines.push_back("illustrate");
    lines.push_back("framing");

    vector<string> result = frame(lines);

    for(auto it = result.cbegin(); it != result.cend(); ++it) {
        cout << *it << endl;
    }

    vector<string> result2 = vertical_cat(lines, result);
    for(auto it = result2.cbegin(); it != result2.cend(); ++it) {
        cout << *it << endl;
    }

    result2 = horizontal_cat(lines, result);
    for(auto it = result2.cbegin(); it != result2.cend(); ++it) {
        cout << *it << endl;
    }

    return 0;
}