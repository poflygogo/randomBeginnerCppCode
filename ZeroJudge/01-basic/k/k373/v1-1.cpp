#include <iostream>
#include <set>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::set<std::string> seen;
    std::string s;
    int flag;
    while (std::cin >> s >> flag)
    {
        if (flag == 0 && !seen.count(s))
        {
            seen.insert(s);
            std::cout << s << '\n';
        }
    }
}
