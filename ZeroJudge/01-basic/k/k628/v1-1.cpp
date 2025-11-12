#include <array>
#include <iostream>

int main()
{
    const std::string vowels = "AEIOUaeiou";
    int n;
    std::string kingdom, res;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        std::getline(std::cin, kingdom);
        if (kingdom.back() == 'y')
        {
            res = "nobody";
        }
        else if (vowels.find(kingdom.back()) != std::string::npos)
        {
            res = "Alice";
        }
        else
        {
            res = "Bob";
        }

        std::cout << "Case #" << i << ": " << kingdom << " is ruled by " << res << ".\n";
    }
}
