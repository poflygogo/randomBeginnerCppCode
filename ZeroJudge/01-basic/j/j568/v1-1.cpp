#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t, n, a, b, c;
    std::cin >> t;
    while (t--)
    {
        std::cout << "請使用配方法解下列一元二次方程式" << "\n\n";
        std::cin >> n;
        std::string res;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a >> b >> c;

            if (a < 0)
            {
                res += '-';
                a = std::abs(a);
            }
            if (a > 1)
            {
                res += std::to_string(a);
            }
            res += "x^2";

            if (b)
            {
                if (b < 0)
                {
                    res += '-';
                    b = std::abs(b);
                }
                else
                {
                    res += '+';
                }
                if (b > 1)
                {
                    res += std::to_string(b) + "x";
                }
                else if (b == 1)
                {
                    res += 'x';
                }
            }

            if (c)
            {
                if (c < 0)
                {
                    res += std::to_string(c);
                }
                else
                {
                    res += '+' + std::to_string(c);
                }
            }

            std::cout << i << ". " << res << "=0\n\n";
            res.clear();
        }
        std::cout << "考試要加油口屋\n";
    }
}
