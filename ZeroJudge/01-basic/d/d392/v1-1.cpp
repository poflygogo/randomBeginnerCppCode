#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    istringstream iss;
    int sum, num;
    string s;
    while (getline(cin, s))
    {
        iss.clear();
        iss.str(s);
        sum = 0;
        while (iss >> num)
        {
            sum += num;
        }
        cout << sum << '\n';
    }
}
