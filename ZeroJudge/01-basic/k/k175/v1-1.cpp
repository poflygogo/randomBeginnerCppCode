#include <cmath>
#include <iomanip>
#include <iostream>

#define pi std::acos(-1)

double calc(double n)
{
    return pi - n * std::sin(pi / n);
}

int main()
{
    double n;
    std::cin >> n;
    std::cout << std::setprecision(2) << std::scientific << calc(n);
}
