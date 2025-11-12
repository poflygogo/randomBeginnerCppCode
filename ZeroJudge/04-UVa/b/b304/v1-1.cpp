#include <iostream>
#include <map>
#include <stack>

bool ParenthesesBalance(std::string s) {
    static const std::map<char, char> bracket = {{')', '('}, {']', '['}};
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (!st.empty() && bracket.at(c) == st.top()) {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(128, '\n');
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        std::cout << (ParenthesesBalance(s) ? "Yes" : "No") << '\n';
    }
}
