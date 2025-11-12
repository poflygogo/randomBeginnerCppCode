#include <iostream>

int main()
{
    std::string s;
    int comm;
    std::getline(std::cin, s);
    std::cin >> comm;
    switch (comm)
    {
    case 1:
        s[0] = std::toupper(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            s[i] = std::tolower(s[i]);
        }
        break;
    case 2:
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = std::toupper(s[i]);
        }
        break;
    case 3:
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 || !std::isalpha(s[i - 1]))
            {
                s[i] = std::toupper(s[i]);
            }
            else
            {
                s[i] = std::tolower(s[i]);
            }
        }
        break;
    case 4:
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = std::tolower(s[i]);
        }
        break;
    default:
        break;
    }

    std::cout << s;
}
