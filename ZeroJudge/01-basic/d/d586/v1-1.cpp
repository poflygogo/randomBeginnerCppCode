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
        std::cin >> m >> item;
        m--;
        if (!isalpha(item[0]))
        {
            std::cout << int_to_c[std::stoi(item) - 1];
            while (m--)
            {
                std::cin >> item;
                std::cout << int_to_c[std::stoi(item) - 1];
            }
        }
        else
        {
            int res = c_to_int.find(item) + 1;
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
