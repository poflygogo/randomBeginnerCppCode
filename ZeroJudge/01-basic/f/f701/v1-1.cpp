#include <iostream>
#include <sstream>

int main()
{
    std::istringstream iss;
    std::string s, conj;
    std::getline(std::cin, s);
    std::getline(std::cin, conj);
    iss.str(s);
    iss >> s;
    std::cout << s;
    while (iss >> s)
    {
        std::cout << ' ' << conj << ' ' << s;
    }
}
