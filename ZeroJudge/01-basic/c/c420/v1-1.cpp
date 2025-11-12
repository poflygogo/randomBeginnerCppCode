#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << string(n - i - 1, '_') << string(i * 2 + 1, '*') << string(n - i - 1, '_') << '\n';
    }
}
