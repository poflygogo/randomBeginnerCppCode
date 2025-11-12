#include <bitset>
#include <iostream>
using namespace std;

int main()
{
    const int kLimit = 15;
    int n;
    bitset<kLimit> bit;
    while (cin >> n)
    {
        for (int i = 0; i < (1 << n); i++)
        {
            bit = i;
            for (int j = n - 1; j >= 0; j--)
            {
                cout << bit[j];
            }
            cout << '\n';
        }
    }
}
