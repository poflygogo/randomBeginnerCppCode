#include <iostream>
using namespace std;

int main()
{
    int t, y;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> y;
        cout << "Case " << i << ": a " << ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0) ? "leap" : "normal") << " year\n";
    }
}
