#include <iostream>
using namespace std;

int main()
{
    string n;
    while (cin >> n)
    {
        int sum = 0;
        for (auto &&c : n)
        {
            sum += c - '0';
        }
        cout << (sum % 3 == 0 ? "yes" : "no") << '\n';
    }
}
