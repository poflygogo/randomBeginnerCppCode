// ZeroJudge a017 五則運算
// C++14

#include <cctype>   // isdigit
#include <sstream>  // istringstream
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

// 根據傳入的值進行簡單計算
int calc(const int a, const int b, const char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        return b / a;
    case '%':
        return b % a;
    }
    return 0;  // should not happen
}

// 判斷一個字串是否全是數字
bool isNumeric(const std::string &s) {
    for (const char c : s) {
        if (!std::isdigit(c)) { return false; }
    }
    return true;
}

// 解析中序運算式並計算結果
int eval(std::istringstream &iss) {
    static const std::unordered_map<char, int> kWeight = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}};

    std::stack<int> nums;
    std::stack<char> op;  // operator

    std::string s;
    while (iss >> s) {
        if (isNumeric(s)) {
            nums.push(std::stoi(s));
        } else if (s == "(") {
            // 左括號進入遞迴
            nums.push(eval(iss));
        } else if (s == ")") {
            // 右括號強制退出迴圈
            break;
        } else {
            char c = s.front();
            while (!op.empty() && kWeight.at(c) <= kWeight.at(op.top())) {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(calc(a, b, op.top()));
                op.pop();
            }
            op.push(c);
        }
    }

    // 清空 stack 中尚未計算完畢的數值
    while (!op.empty()) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        nums.push(calc(a, b, op.top()));
        op.pop();
    }

    return nums.top();
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::cout << eval(iss) << '\n';
    }
}
