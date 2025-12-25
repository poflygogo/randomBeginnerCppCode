// UVa 727 - Postfix Expression
// ZeroJudge d285
// C++14

#include <algorithm>  // find_if
#include <cctype>     // isdigit
#include <iostream>
#include <limits>  // numeric_limit
#include <stack>
#include <string>

// remove unexpect space characters, ie ' ', '\n', '\r', '\t'
// 非必要，只是預防萬一測資格式在搞
std::string stringTrim(const std::string &s) {
    using std::find_if;
    auto it1 = find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isspace(ch); });
    if (it1 == s.end()) { return ""; }

    auto it2 = find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); });
    return std::string(it1, it2.base());
}

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

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');  // ignore t to '\n'
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');  // ignore blank line

    bool is_first_case = true;
    while (t--) {
        if (!is_first_case) { std::cout << '\n'; }
        is_first_case = false;

        std::string s;
        std::stack<char> st;  // operators

        while (std::getline(std::cin, s)) {
            s = stringTrim(s);

            // 防禦性檢查: ZeroJudge 老毛病了，測字格式可能不符題目所述
            // 我不想賭，所以多檢查 s.size() >= 2
            if (s.empty() || s.size() >= 2) { break; }

            char c = s.front();
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
        }

        // clean the stack
        while (!st.empty()) {
            std::cout << st.top();
            st.pop();
        }
        std::cout << '\n';
    }
}
