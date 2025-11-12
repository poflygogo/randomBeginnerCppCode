#include <iostream>

void divide(int &n, const int divisor)
{
    while (n % divisor == 0)
    {
        n /= divisor;
    }
}

int main()
{
    int n;
    std::cin >> n;
    divide(n, 2);
    divide(n, 3);
    divide(n, 5);

    std::cout << (n == 1 ? "ugly" : "beautiful");
}
