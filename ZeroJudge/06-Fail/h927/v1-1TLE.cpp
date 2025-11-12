#include <algorithm>
#include <iostream>

int main()
{
    int n, m;
    std::string a, b;
    std::cin >> n >> m >> a >> b;

    int lft = std::count(b.begin(), b.end(), '1');
    int rgt = m - lft;

    std::string bit;
    bit.reserve(m + a.size());

    bit += std::string(lft, '1');
    bit += a;
    bit += std::string(rgt, '0');

    int res = 0;
    int base = 1;
    for (int i = bit.size() - 1; i >= 0; i--)
    {
        if (bit[i] == '1')
        {
            res += base;
            res %= 9982445353;
        }
        base *= 2;
    }

    std::cout << res;
}
