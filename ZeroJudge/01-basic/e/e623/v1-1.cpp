#include <array>
#include <iostream>

const std::array<std::string, 4> ppap = {"Pineapple pen", "Apple", "Pineapple", "Pen"};

int main()
{
    int num, n;
    std::cin >> num;
    for (n = 1; (n + 1) * n * 2 < num; n++) {}
    std::cout << ppap[((n + 1) * n * 2 - num) / n];
}
