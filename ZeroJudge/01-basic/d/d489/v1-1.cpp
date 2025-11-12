#include <iostream>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long s = a + b + c;
    cout << s * (s - 2 * a) * (s - 2 * b) * (s - 2 * c) / 16;
}
