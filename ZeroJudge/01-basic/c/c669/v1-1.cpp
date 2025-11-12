#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;

void Solve(stringstream &ss)
{
    int num, dupe;
    int min_val = __INT_MAX__;
    int max_val = -__INT_MAX__ - 1;
    int sum = 0;
    int item_cnt = 0;
    unordered_set<int> seen;
    while (ss >> num)
    {
        item_cnt += 1;
        sum += num;
        if (num < min_val)
        {
            min_val = num;
        }
        if (num > max_val)
        {
            max_val = num;
        }
        if (seen.find(num) != seen.end())
        {
            dupe = num;
        }
        else
        {
            seen.insert(num);
        }
    }

    cout << (max_val + min_val) * item_cnt / 2 - sum + dupe << ' ' << dupe << '\n';
}

int main()
{
    int t, tmp;
    vector<int> arr;
    stringstream ss;
    string s;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin, s);
        ss.str(s);
        Solve(ss);
        ss.clear();
        ss.str("");
    }
}
