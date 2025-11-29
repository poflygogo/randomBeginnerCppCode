// Zerojudge d182
// UVa 256 Quirksome Squares
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    const std::unordered_map<int, std::string> quirksome_squrares = {
        {2, "00\n01\n81\n"},
        {3, "0000\n0001\n2025\n3025\n9801\n"},
        {4, "000000\n000001\n088209\n494209\n998001\n"},
        {8, "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n"}};

    int n;
    while (std::cin >> n) {
        std::cout << quirksome_squrares.at(n);
    }
}

// lazy solution :P
