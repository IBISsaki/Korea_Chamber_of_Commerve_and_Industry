#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    cout << "input your name : ";
    string name;
    cin >> name;

    const int pad = 2;

    const string greeting = "hello, " + name + "!";
    const int rows = 3 + 2 * pad;
    const string::size_type cols = greeting.size() + 2 + 2 * pad;

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c = c + greeting.size();
            } else if (r == 0 || r == rows-1 || c == 0 || c == cols-1)  {
                cout << "*";
                ++c;
            } else {
                cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}