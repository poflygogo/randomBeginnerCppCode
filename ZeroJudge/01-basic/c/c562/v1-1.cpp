#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    const map<char, int> kTable = {{'0', 1}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0},
                                   {'5', 0}, {'6', 1}, {'7', 0}, {'8', 2}, {'9', 1}};
    string s;
    while (cin >> s)
    {
        int cnt = 0;
        for (char c : s)
        {
            cnt += kTable.at(c);
        }
        cout << cnt << '\n';
    }
}
