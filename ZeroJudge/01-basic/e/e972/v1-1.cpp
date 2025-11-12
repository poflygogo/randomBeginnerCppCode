#include <iomanip>
#include <iostream>

int main()
{
    double money, cost;
    char currency;
    std::cin >> money >> cost >> currency;
    switch (currency)
    {
    case 'T':
        money /= 1.0;
        break;
    case 'U':
        money /= 30.9;
        break;
    case 'J':
        money /= 0.28;
        break;
    case 'E':
        money /= 34.5;
        break;
    default:
        // should not happen
        std::cout << "[Error] Invalid currency. Expect 'TUJE', got='" << currency << "'\n";
        return 0;
    }
    money -= cost;
    if (money < 0)
    {
        std::cout << "No Money";
    }
    else
    {
        std::cout << currency << ' ' << std::fixed << std::setprecision(2)
                  << (money < 0.05 ? 0 : money);
    }
}
