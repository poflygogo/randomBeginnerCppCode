#include <iostream>
#include <string>

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n, m, k;
    std::string s, tmp;
    while (std::cin >> n >> m && n && m)
    {
        while (n--)
        {
            std::cin >> tmp;
            s += tmp;
        }
        while (m--)
        {
            std::cin >> k;
            std::cout << s[k - 1];
        }
        std::cout << '\n';
        s.clear();
    }
}
