#include <iomanip>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s.front()
              << std::setw(3) << std::setfill('0') << std::right << s.substr(1, s.size());
}
