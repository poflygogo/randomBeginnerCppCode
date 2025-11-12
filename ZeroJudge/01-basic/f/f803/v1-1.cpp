#include <iostream>
#include <vector>

int find(const std::vector<int> &arr, const int target)
{
    int lft = 0;
    int rgt = arr.size() - 1;
    while (lft <= rgt)
    {
        int mid = (lft + rgt) / 2;
        if (arr[mid] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] > target)
        {
            rgt = mid - 1;
        }
        else
        {
            lft = mid + 1;
        }
    }
    return -1;
}

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
        std::cout << find(prime, target) << '\n';
    }
}
