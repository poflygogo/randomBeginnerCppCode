#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << std::stoi(s, nullptr, 2);
}
