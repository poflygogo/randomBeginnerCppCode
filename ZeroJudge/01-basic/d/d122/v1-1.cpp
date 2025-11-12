#include <iostream>
using namespace std;

int Solve(long long n)
{
    if (n < 5)
    {
        return 0;
    }
    n /= 5;
    return n + Solve(n);
}

int main()
{
    long long n;
    while (cin >> n)
    {
        cout << Solve(n) << '\n';
    }
}
