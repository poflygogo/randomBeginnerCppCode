#include <iostream>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    bool flag = s != "print";
    int cnt = 0;
    int sum = 0;
    for (int i = 1 + flag; i <= n - flag; i++)
    {
        if (n % i == 0)
        {
            std::cout << i << '\n';
            cnt += 1;
            sum += i;
        }
    }
    std::cout << n << "的因數的個數是" << cnt << "，" << n << "的因數的總和是" << sum;
}
