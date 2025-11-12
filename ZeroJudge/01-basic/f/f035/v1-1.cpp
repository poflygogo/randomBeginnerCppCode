#include <iostream>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::cout << int(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        std::cout << '_' << int(s[i]);
    }
}
