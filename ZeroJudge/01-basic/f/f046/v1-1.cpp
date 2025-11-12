#include <iostream>

int main()
{
    int width, target;
    std::string s;
    std::cin >> width;
    std::cin.ignore();
    std::getline(std::cin, s);
    std::cin >> target;
    s = std::string(width, ' ') + s + std::string(width, ' ');
    std::cout << s.substr(target, width);
}
