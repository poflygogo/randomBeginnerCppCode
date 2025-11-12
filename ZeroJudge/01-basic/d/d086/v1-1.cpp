#include <iostream>
using namespace std;

string Solve(const string &s)
{
    int sum = 0;
    for (auto &&c : s)
    {
        if (!isalpha(c))
        {
            return "Fail";
        }
        sum += tolower(c) - 'a' + 1;
    }
    return to_string(sum);
}

int main()
{
    string s;
    while (cin >> s && s != "0")
    {
        cout << Solve(s) << '\n';
    }
}
