#include <iostream>

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (a + b != b + a)
        {
            std::cout << "= =\n";
        }
        else
        {
            int len = GCD(a.size(), b.size());
            std::cout << a.substr(0, len) << '\n';
        }
    }
}
