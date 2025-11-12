#include <iostream>
using namespace std;

int main()
{
    int t, y;
    cin >> t;
    while (t--)
    {
        cin >> y;
        cout << "a " << ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0) ? "leap" : "normal") << " year\n";
    }
}
