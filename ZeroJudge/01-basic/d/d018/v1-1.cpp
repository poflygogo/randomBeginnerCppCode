#include <iostream>
#include <sstream>
using namespace std;

double Solve(istringstream ss)
{
    int id;
    double val, res = 0;
    char colon; // 只是一個佔位符
    while (ss >> id >> colon >> val)
    {
        if (id % 2 == 0)
        {
            res -= val;
        }
        else
        {
            res += val;
        }
    }
    return res;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << Solve(istringstream(line)) << '\n';
    }
}
