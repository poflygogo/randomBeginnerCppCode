#include <iostream>

int main()
{
    int cnt = 0;
    int sum = 0;
    int curr;
    while (std::cin >> curr)
    {
        sum += curr;
        cnt++;
    }
    std::cout << (sum % cnt ? sum % cnt : cnt);
}
