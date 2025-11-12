#include <iostream>
#include <list>

int main()
{
    long long k;
    std::cin >> k;
    std::list<long long> arr;

    for (long long i = 1; i < 10; i++)
    {
        arr.push_back(i);
    }

    for (int i = 0; i < k - 1; i++)
    {
        long long item = arr.front();
        arr.pop_front();
        if (item % 10 != 0)
        {
            arr.push_back(item * 10 + item % 10 - 1);
        }
        arr.push_back(item * 10 + item % 10);
        if (item % 10 != 9)
        {
            arr.push_back(item * 10 + item % 10 + 1);
        }
    }
    std::cout << arr.front();
}
