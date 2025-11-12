#include <iostream>

int main()
{
    std::string s;
    std::getline(std::cin, s);

    // capitalize
    s[0] = std::toupper(s.front());
    for (int i = 1; i < s.size(); i++)
    {
        s[i] = std::tolower(s[i]);
    }
    std::cout << s << '\n';

    // upper
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = std::toupper(s[i]);
    }
    std::cout << s << '\n';

    // title
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = (i == 0 || !std::isalpha(s[i - 1]) ? std::toupper(s[i]) : std::tolower(s[i]));
    }
    std::cout << s << '\n';

    // lower
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = std::tolower(s[i]);
    }
    std::cout << s << '\n';
}
