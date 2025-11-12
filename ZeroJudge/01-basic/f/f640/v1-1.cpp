#include <iostream>
#include <string>

int Solve()
{
    std::string token;
    std::cin >> token;
    if (token == "f")
    {
        int x = Solve();
        return 2 * x - 3;
    }
    else if (token == "g")
    {
        int x = Solve();
        int y = Solve();
        return 2 * x + y - 7;
    }
    else if (token == "h")
    {
        int x = Solve();
        int y = Solve();
        int z = Solve();
        return 3 * x - 2 * y + z;
    }
    else
    {
        return std::stoi(token);
    }
}

int main()
{
    std::cout << Solve();
}
