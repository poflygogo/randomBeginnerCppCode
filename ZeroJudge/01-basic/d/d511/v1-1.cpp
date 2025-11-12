#include <iostream>
using namespace std;

int main()
{
    int period = 5;
    int cnt = 0;
    int a, b, c;
    while (period--)
    {
        cin >> a >> b >> c;
        if (a > c)
        {
            swap(a, c);
        }
        if (b > c)
        {
            swap(b, c);
        }
        cnt += ((a + b) > c);
    }
    cout << cnt;
}
