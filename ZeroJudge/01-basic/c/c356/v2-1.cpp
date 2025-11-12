#include <iostream>
#include <vector>
using namespace std;

int main()
{
    short n;
    cin >> n;
    cin.ignore();
    vector<char> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin.read(s.data(), n);
        cout << s.data()[i];
    }
}
