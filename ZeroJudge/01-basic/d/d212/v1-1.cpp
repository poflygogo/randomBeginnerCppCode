#include <array>
#include <iostream>
using namespace std;

int main()
{
    const int kLimit = 100;
    array<long long, kLimit> dp = {1, 1};
    for (int i = 2; i < kLimit; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << '\n';
    }
}
