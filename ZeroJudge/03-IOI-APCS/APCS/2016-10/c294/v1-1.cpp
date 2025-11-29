// Zerojudge c294
// APCS 2016-10 1 三角形辨別
// c++14

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

// 太簡單了，順便練習用 Enum
// 實際上直接返回 string 或直接輸出就好
enum class TriangleType {
    NotTriangle,
    ObtuseTriangle,
    RightTriangle,
    AcuteTriangle,
};

TriangleType CheckTriangleType(int a, int b, int c) {
    if (a + b <= c) {
        return TriangleType::NotTriangle;
    }
    if (a * a + b * b < c * c) {
        return TriangleType::ObtuseTriangle;
    }
    if (a * a + b * b == c * c) {
        return TriangleType::RightTriangle;
    }
    return TriangleType::AcuteTriangle;
}

int main() {
    constexpr int kSides = 3;
    std::array<int, kSides> sides;
    for (auto &side : sides) {
        std::cin >> side;
    }
    std::sort(sides.begin(), sides.end());

    const std::string kTriangleTypeString[] = {
        "No",
        "Obtuse",
        "Right",
        "Acute",
    };

    std::cout << sides[0] << ' ' << sides[1] << ' ' << sides[2] << '\n';
    std::cout << kTriangleTypeString[(int)CheckTriangleType(sides[0], sides[1], sides[2])];
}
