#include <iostream>
using namespace std;

int main()
{
    string split, line;
    getline(cin, split);
    getline(cin, line);
    int i = 0;
    int j = line.find(split);
    while (j != string::npos)
    {
        cout << line.substr(i, j - i) << '\n';
        i = j + split.size();
        j = line.find(split, i);
    }
    cout << line.substr(i) << '\n';
}
