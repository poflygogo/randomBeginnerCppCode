#include <algorithm>
#include <iostream>
using namespace std;

const string kTokens = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Converter(string num, int base1, int base2)
{
    // to int
    int n = 0;
    for (char c : num)
    {
        n = n * base1 + kTokens.find(c);
    }

    // to base2
    string res;
    while (n)
    {
        res += kTokens[n % base2];
        n /= base2;
    }
    if (res.empty())
    {
        res = "0";
    }
    else
    {
        reverse(res.begin(), res.end());
    }
    return res;
}

int main()
{
    string num;
    int base1, base2;
    while (cin >> num >> base1 >> base2)
    {
        cout << Converter(num, base1, base2) << '\n';
    }
}
