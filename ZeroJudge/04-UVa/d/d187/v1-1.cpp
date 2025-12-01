// Zerojudge 187
// UVa 11530 - SMS Typing
// C++14
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

int countSMSTyping(const std::string &s) {
    static const std::unordered_map<char, int> keys = {
        {'a', 1}, {'d', 1}, {'g', 1}, {'j', 1}, {'m', 1}, {'p', 1}, {'t', 1}, {'w', 1}, {' ', 1},
        {'b', 2}, {'e', 2}, {'h', 2}, {'k', 2}, {'n', 2}, {'q', 2}, {'u', 2}, {'x', 2}, {'c', 3},
        {'f', 3}, {'i', 3}, {'l', 3}, {'o', 3}, {'r', 3}, {'v', 3}, {'y', 3}, {'s', 4}, {'z', 4}};
    int sum = 0;
    for (char c : s) sum += keys.at(c);
    return sum;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    for (int test_case = 1; test_case <= t; ++test_case) {
        std::string s;
        std::getline(std::cin, s);
        std::cout << "Case #" << test_case << ": " << countSMSTyping(s) << '\n';
    }
}
