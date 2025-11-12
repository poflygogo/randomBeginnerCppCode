#include <iostream>
using namespace std;

/**
 * @brief custom power
 * @details
 * same as base^num.
 * eg. pow(2, 3) = 2^3 = 2 * 2 * 2 = 8
 * @param base base number
 * @param exp exponent
 * @return int
 */
int pow(int base, int exp)
{
    int res = 1;
    while (exp--)
    {
        res *= base;
    }
    return res;
}

/**
 * @brief check if input value is Armstrong Number.
 * @details
 * An Armstrong number is a n digits number.
 * The sum of each digit raised to the power of n is equal to the number itself.
 * eg. 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * @param n [in]
 * @return true if is Armstrong else false
 */
bool is_armstrong(int n)
{
    int digit = 1; ///< 幾位數
    int sum = 0;   ///< 等於每一位數的digit次方和
    int m = n;     ///< 暫存數字
    while (m /= 10)
    {
        digit++;
    }
    m = n;
    do
    {
        sum += pow(m % 10, digit);
    } while (m /= 10);
    return sum == n;
}

int main()
{
    int a, b;
    bool flag = true;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (is_armstrong(i))
        {
            cout << i << " ";
            flag = false;
        }
    }
    if (flag)
    {
        cout << "none" << endl;
    }
    else
    {
        cout << endl;
    }
}