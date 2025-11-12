#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s.front() << std::string(s.size() - 2, '_') << s.back();
}
