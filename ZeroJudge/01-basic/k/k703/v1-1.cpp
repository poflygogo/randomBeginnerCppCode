#include <iostream>

int main()
{
    const std::string shop = "商店";

    int n;
    int cnt = 0;
    std::string s;
    std::cin >> n;
    std::cin.ignore();
    while (n--)
    {
        std::getline(std::cin, s);
        if (s.find(shop) != std::string::npos)
        {
            cnt++;
        }
    }
    std::cout << cnt;
}
