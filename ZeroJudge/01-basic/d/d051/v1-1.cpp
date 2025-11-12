#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    cout << fixed << setprecision(3) << (n - 32) / 1.8;
}
