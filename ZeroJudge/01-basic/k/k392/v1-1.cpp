#include <cmath>
#include <iomanip>
#include <iostream>

double func(double n)
{
    if (n > 10)
    {
        return 2 * std::sqrt(n);
    }
    else if (n > -10)
    {
        return n * (-0.5) + 10;
    }
    else
    {
        return std::abs(std::pow(n, 5)) - 33;
    }
}

int main()
{
    double n;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(1) << func(n);
}
