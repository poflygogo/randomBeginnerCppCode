#include <iostream>
using namespace std;

int main()
{
    const int kLimit = 15;
    int n;
    char line[kLimit + 2]; // 多兩個空間容納 '\n'與'\0'
    while (cin >> n)
    {
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                line[j] = ((i >> (n - 1 - j)) & 1) + '0';
            }
            line[n] = '\n';
            line[n + 1] = '\0';
            cout.write(line, n + 1);
        }
    }
    return 0;
}
