#include <iostream>

std::pair<int, int> nAnB(const std::string &target, const std::string &guess)
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] == guess[i])
        {
            a++;
        }
    }
    for (const char c : guess)
    {
        if (target.find(c) != std::string::npos)
        {
            b++;
        }
    }
    b -= a;
    return {a, b};
}

int main()
{
    std::string target, guess;
    int m;
    std::cin >> target >> m;
    while (m--)
    {
        std::cin >> guess;
        std::pair<int, int> res = nAnB(target, guess);
        std::cout << res.first << 'A' << res.second << 'B' << '\n';
    }
}
