#include <iostream>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::cout << s << '\n';
    std::cout << std::string(s.size(), '~');
}
