// 全國中等學校102學年度商業類科學生技藝競賽
// c++ 14

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int eval(string &s) {
    static string operators = "+-*/%";
    int num1 = 0;
    int num2 = 0;
    char op = 0;

    for (char c : s) {
        if (isdigit(c)) {
            int &num = (op == 0 ? num1 : num2);
            num *= 10;
            num += c - '0';
        } else if (operators.find(c) != string::npos) {
            op = c;
        }
    }

    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '%': return num1 % num2;
        default: return 0;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<int>::max(), '\n');
    while (n--) {
        string s;
        getline(cin, s);
        cout << s << '\n';
        cout << eval(s) << '\n';
    }
}
