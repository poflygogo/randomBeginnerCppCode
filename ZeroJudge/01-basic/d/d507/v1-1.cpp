#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a *= a;
    b *= b;
    c *= c;
    if (a + b == c || a + c == b || b + c == a)
        cout << "right triangle" << endl;
    else if (c > a + b || b > a + c || a > b + c)
        cout << "obtuse triangle" << endl;
    else
        cout << "acute triangle" << endl;
}
