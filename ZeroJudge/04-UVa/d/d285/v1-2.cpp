// UVa 727 - Postfix Expression
// ZeroJudge d285
// C++14

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int priority(const char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:  // '(', ')', digits
        return 0;
    }
}

bool process(const std::string &line, std::stack<char> &st) {
    char c = ' ';
    std::istringstream iss(line);
    iss >> c;
    if (iss.fail()) {
        return false;  // 告訴主迴圈該停了
    }

    switch (c) {
    case '(':
        st.push(c);
        break;

    case ')':
        while (st.top() != '(') {
            std::cout << st.top();
            st.pop();
        }
        st.pop();  // pop '('
        break;

    case '+':
    case '-':
    case '*':
    case '/':
        while (!st.empty() && priority(st.top()) >= priority(c)) {
            std::cout << st.top();
            st.pop();
        }
        st.push(c);
        break;

    default:
        std::cout << c;  // number, ouput directly
        break;
    }

    return true;  // 告訴主迴圈繼續
}

int main() {
    int t;
    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    iss >> t;
    std::getline(std::cin, s);

    bool is_first_case = true;
    while (t--) {
        if (!is_first_case) { std::cout << '\n'; }
        is_first_case = false;

        std::stack<char> st;  // operators
        while (std::getline(std::cin, s) && process(s, st)) {}

        while (!st.empty()) {
            std::cout << st.top();
            st.pop();
        }
        std::cout << '\n';
    }
}
