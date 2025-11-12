#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, m, target;
    std::cin >> n >> m;
    std::vector<int> prime;

    // sieve
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    while (m--)
    {
        std::cin >> target;
        std::cout << std::lower_bound(prime.begin(), prime.end(), target) - prime.begin() + 1 << '\n';
    }
}
