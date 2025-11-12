#include <iostream>

int main()
{
    using namespace std;
    string a, b;
    cin >> a >> b;
    std::cout << '|'
              << a << string(10 - a.size(), ' ') << '|'
              << string(10 - b.size(), ' ') << b << '|';
}
