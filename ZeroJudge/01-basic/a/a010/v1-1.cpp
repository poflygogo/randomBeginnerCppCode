#include <iostream>
using namespace std;

int main()
{
    // num = 待處理的數字
    // exp = 指數 exponent
    // is_first 標記是否是第一個數字
    unsigned int num, exp, is_first;
    is_first = 1;
    cin >> num;
    for (int base = 2; base <= num; base++)
    {
        if (num % base == 0)
        {
            exp = 0;
            do
            {
                num /= base;
                exp += 1;
            } while (num % base == 0);
            if (!is_first)
                cout << " * ";
            is_first = 0;
            if (exp == 1)
                cout << base;
            else if (exp > 1)
                cout << base << "^" << exp;
        }
    }
}