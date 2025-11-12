#include <iostream>
#include <sstream>
using namespace std;

bool isdigit(const string &s)
{
    for (auto &&c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

int Solve(istringstream ss)
{
    int sum = 0;
    string s;
    while (ss >> s)
    {
        if (isdigit(s))
        {
            sum += stoi(s);
        }
    }
    return sum;
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << Solve(istringstream(s)) << '\n';
    }
}
