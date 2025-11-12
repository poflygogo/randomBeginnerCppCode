#include <iomanip>
#include <iostream>

int main()
{
    double a, b, c, d, determinant;
    while (std::cin >> a >> b >> c >> d)
    {
        determinant = a * d - b * c;
        if (determinant == 0)
        {
            std::cout << "cheat!\n";
        }
        else
        {
            std::cout << std::fixed << std::setprecision(5) << d / determinant << ' ' << -b / determinant << '\n';
            std::cout << std::fixed << std::setprecision(5) << -c / determinant << ' ' << a / determinant << '\n';
        }
    }
}
