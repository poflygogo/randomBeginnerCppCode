#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    a += a & 1;
    b -= b & 1;
    cout << (a + b) * ((b - a) / 2 + 1) / 2;
}
