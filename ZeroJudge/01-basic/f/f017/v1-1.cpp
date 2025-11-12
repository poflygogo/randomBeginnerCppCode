#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s.front();
    for (size_t i = 1; i < s.size(); i++)
    {
        std::cout << '-' << s[i];
    }
}
