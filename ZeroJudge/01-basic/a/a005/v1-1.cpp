#include <iostream>
using namespace std;
#define SPACE " "

int main()
{
    unsigned int t;
    unsigned int a1, a2, a3, a4, a5;
    cin >> t;
    while (t--)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        if (a2 - a1 == a3 - a2)
        {
            a5 = a4 * 2 - a3;
        }
        else
        {
            a5 = a4 * a4 / a3;
        }
        cout << a1 << SPACE << a2 << SPACE << a3 << SPACE << a4 << SPACE << a5 << endl;
    }
    return 0;
}
