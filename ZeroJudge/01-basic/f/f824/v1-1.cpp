#include <iostream>
#include <map>
#include <vector>

const std::map<std::string, int> ChineseToNum = {
    {"一", 1}, {"二", 2}, {"三", 3}, {"四", 4}, {"五", 5},
    {"六", 6}, {"七", 7}, {"八", 8}, {"九", 9}, {"十", 10}};
const std::map<int, std::string> NumToChinese = {
    {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"}, {5, "五"},
    {6, "六"}, {7, "七"}, {8, "八"}, {9, "九"}, {10, "十"}};

std::string Solve(std::string &s) {
    std::string a = s.substr(0, 3);
    std::string b = s.substr(3, 3);
    std::string c = s.substr(6, 3);
    if (!(b == "有" || b == "又")) {
        return "謬";
    }

    int sum = ChineseToNum.at(a) + ChineseToNum.at(c);
    if (sum == 20) {
        return "二十";
    } else if (sum == 10) {
        return "十";
    } else if (sum > 10) {
        return "十" + NumToChinese.at(sum % 10);
    } else {
        return NumToChinese.at(sum);
    }
}

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        std::cout << Solve(s) << '\n';
    }
}
