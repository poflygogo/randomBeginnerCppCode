#include <iostream>
#include <string>
#include <vector>

struct ThreeSquare {
    int num1, num2, num3;

    ThreeSquare() : num1(-1), num2(-1), num3(-1) {};
    ThreeSquare(int a, int b, int c) : num1(a), num2(b), num3(c) {};

    std::string to_string() {
        std::string s = std::to_string(num1);
        s += " " + std::to_string(num2);
        s += " " + std::to_string(num3);
        return s;
    }
};

int main() {
    constexpr int kLimit = 50000;  // 題目明確說明僅考慮 5000 以內的數

    // 所有數字的平方
    std::vector<int> sqr = {};
    for (int i = 0; i * i <= kLimit; ++i) sqr.push_back(i * i);

    // 建表，將 kLimit 以內的答案都列舉出來
    std::vector<ThreeSquare> result(kLimit + 1, ThreeSquare());
    for (int i = 0; i < sqr.size(); i++) {
        for (int j = i; j < sqr.size(); j++) {
            for (int k = j; k < sqr.size(); k++) {
                int ans = sqr[i] + sqr[j] + sqr[k];
                if (ans <= kLimit && result[ans].num1 == -1) { result[ans] = {i, j, k}; }
            }
        }
    }

    // 查表
    int n;
    std::cin >> n;
    while (n--) {
        int k;
        std::cin >> k;
        if (result[k].num1 == -1) {
            std::cout << -1 << '\n';
        } else {
            std::cout << result[k].to_string() << '\n';
        }
    }
}
