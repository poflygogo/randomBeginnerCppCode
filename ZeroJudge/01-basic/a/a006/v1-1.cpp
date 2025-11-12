#include <iostream>
#include <math.h>       // 要匯入這個才有 sqrt 可以用

int main()
{
    int a, b, c, valid;
    std::cin >> a >> b >> c;
    valid = b * b - 4 * a * c;
    if (valid < 0)
    {
        std::cout << "No real root" << std::endl;
    }
    else if (valid == 0)
    {
        std::cout << "Two same roots x=" << -b / (2 * a) << std::endl;
    }
    else
    {
        int x1, x2;
        valid = sqrt(valid);
        x1 = (-b + valid) / (2 * a);
        x2 = (-b - valid) / (2 * a);
        std::cout << "Two different roots x1=" << x1 << " , x2=" << x2 << std::endl;
    }
    return 0;
}
