#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ans, guess;
    int n;
    int a, b;
    cin >> ans >> n;
    while (n--)
    {
        cin >> guess;
        a = 0;
        b = 0;
        for (const char &c : ans)
        {
            b += count(guess.begin(), guess.end(), c);
        }
        for (int i = 0; i < 4; ++i)
        {
            a += ans[i] == guess[i];
        }
        b -= a;
        cout << a << 'A' << b << 'B' << '\n';
    }
}
