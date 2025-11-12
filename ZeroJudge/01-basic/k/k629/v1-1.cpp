#include <iostream>

int main()
{
    int n = 0;
    int t;
    std::cin >> t;
    std::string line;
    std::cin.ignore();
    while (t--)
    {
        std::getline(std::cin, line);
        if (line[1] == '+')
        {
            n++;
        }
        else if (line[1] == '-')
        {
            n--;
        }
    }
    std::cout << n;
}
