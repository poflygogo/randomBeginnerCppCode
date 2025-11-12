#include <iostream>

void MinusOne(std::string &num)
{
    int i = num.size() - 1;
    num[i] -= 1;
    while (num[i] < '0')
    {
        num[i] += 10;
        i--;
        num[i] -= 1;
    }
    if (num[0] == '0')
    {
        num.erase(0, 1);
    }
}

int main()
{
    std::string num;
    while (std::cin >> num)
    {
        MinusOne(num);
        std::cout << num << '\n';
    }
}
