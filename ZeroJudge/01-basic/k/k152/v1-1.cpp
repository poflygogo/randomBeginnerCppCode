#include <iomanip>
#include <iostream>

int main()
{
    using namespace std;
    string a, b;
    cin >> a >> b;
    cout << '|';
    cout << setw(10) << left  << a << '|';
    cout << setw(10) << right << b << '|';
}
