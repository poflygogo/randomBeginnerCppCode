#include <iostream>
#include <set>

int main()
{
    std::set<std::string> data1, data2;
    std::string s;
    int n, m;
    std::cin >> n >> m;
    while (n--)
    {
        std::cin >> s;
        data1.insert(s);
    }

    while (m--)
    {
        std::cin >> s;
        data2.insert(s);
    }

    int cnt = 0;
    for (const std::string item : data1)
    {
        if (data2.find(item) == data2.end())
        {
            cnt++;
        }
    }

    std::cout << cnt;
}
