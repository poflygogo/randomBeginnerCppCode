#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << 399 * (n >= 60) + 890 * (n >= 18 && n < 60) + 790 * (n >= 12 && n < 18) + 590 * (n >= 6 && n < 12);
}
