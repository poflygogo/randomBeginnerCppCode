#include <iostream>
using namespace std;

int main()
{
    int n, k, w;
    cin >> n >> k >> w;
    int result = n;
    while (n >= k)
    {
        int tmp = (n / k) * w;
        result += tmp;
        n %= k;
        n += tmp;
    }
    cout << result;
}
