#include <iostream>

int Solve(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            int j = n / i;
            if (i != j)
            {
                sum += j;
            }
        }
    }
    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << Solve(n);
}
