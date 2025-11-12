#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    map<int, int> counter;
    while (cin >> n)
    {
        counter[n] += 1;
    }
    for (auto &&i : counter)
    {
        if (i.second % 3)
        {
            cout << i.first;
            return 0;
        }
    }
}
