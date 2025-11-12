#include <iostream>

int main()
{
    std::string a, b, flag;
    std::cin >> a >> b >> flag;
    std::cout << a << (flag == "yes" ? "" : "不") << "想和" << b << "絕交";
}
