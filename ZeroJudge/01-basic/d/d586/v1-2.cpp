#include <iostream>
#include <string>

int main()
{
    const std::string int_to_c = "mjqhofawcpnsexdkvgtzblryui";
    const std::string c_to_int = "uzrmatifxopnhwvbslekycqjgd";
    int n, m;
    std::string item;
    std::cin >> n;
    while (n--)
    {
        std::cin >> m;
        std::cin.ignore(1, ' ');
        if (!isalpha(std::cin.peek()))
        {
            while (m--)
            {
                std::cin >> item;
                std::cout << int_to_c[std::stoi(item) - 1];
            }
        }
        else
        {
            int res = 0;
            while (m--)
            {
                std::cin >> item;
                res += c_to_int.find(item) + 1;
            }
            std::cout << res;
        }
        std::cout << '\n';
    }
}
