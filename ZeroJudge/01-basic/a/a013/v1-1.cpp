// ZeroJudge a013 羅馬數字
// C++14

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>  // abs
#include <utility>  // pair

int romeToInt(const std::string &rome) {
    static const std::unordered_map<char, int> dict = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int result = dict.at(rome.front());
    for (size_t i = 1; i < rome.size(); ++i) {
        if (dict.at(rome[i]) <= dict.at(rome[i - 1])) {
            result += dict.at(rome[i]);
        } else {
            result -= dict.at(rome[i - 1]) * 2;
            result += dict.at(rome[i]);
        }
    }

    return result;
}

std::string intToRome(int num) {
    // 比起原本的數值，再多紀錄一些特例會比較好操作，例如 4 -> IV, 9 -> IX
    static const std::array<std::pair<int, std::string>, 13> dict = {
        {{1000, "M"},
         {900, "CM"},
         {500, "D"},
         {400, "CD"},
         {100, "C"},
         {90, "XC"},
         {50, "L"},
         {40, "XL"},
         {10, "X"},
         {9, "IX"},
         {5, "V"},
         {4, "IV"},
         {1, "I"}}};

    if (num == 0) { return "ZERO"; }

    std::string result;
    for (auto &&item : dict) {
        int n = item.first;
        const std::string &c = item.second;

        while (num >= n) {
            result += c;
            num -= n;
        }
    }
    return result;
}

int main() {
    std::string rome1, rome2;
    while (std::cin >> rome1 && rome1 != "#") {
        std::cin >> rome2;

        int num1 = romeToInt(rome1);
        int num2 = romeToInt(rome2);

        // 題目並未保證地一個數字一定比第二個數字大，所以一定要用 abs，不用的話會 WA(line:8)
        std::cout << intToRome(std::abs(num1 - num2)) << '\n';
    }
}
