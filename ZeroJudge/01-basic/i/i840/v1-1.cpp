#include <array>
#include <iostream>

int main()
{
    constexpr int size = 5;
    std::array<std::string, size> data;
    for (std::string &line : data)
    {
        std::cin >> line;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << data[j][i];
        }
        std::cout << '\n';
    }
}
