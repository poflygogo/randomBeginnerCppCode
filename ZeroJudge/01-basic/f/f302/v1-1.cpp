#include <iostream>

int main()
{
    std::string num_9base;
    std::cin >> num_9base;
    int num = 0;
    for (char c : num_9base)
    {
        num *= 9;
        num += c - '0';
    }
    std::cout << num;
}
