#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    int x = 0, y = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        switch (a)
        {
        case 0:
            y += b;
            break;
        case 1:
            x += b;
            break;
        case 2:
            y -= b;
            break;
        case 3:
            x -= b;
            break;
        default:
            cout << "should not happened. a=" << a;
            return 0;
            break;
        }
    }
    cout << x << ' ' << y;
}
