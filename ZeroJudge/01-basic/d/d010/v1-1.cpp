#include <iostream>
using namespace std;

int FactorsSum(int n)
{
    int res = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res += i;
            if (n / i != i)
            {
                res += n / i;
            }
        }
    }
    return res;
}

int main()
{
    int n, res;
    while (cin >> n)
    {
        res = FactorsSum(n);
        if (res > n)
        {
            cout << "盈數\n";
        }
        else if (res < n)
        {
            cout << "虧數\n";
        }
        else
        {
            cout << "完全數\n";
        }
    }
}
