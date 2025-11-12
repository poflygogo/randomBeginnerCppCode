#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<long long>> data;
    for (long long i = 32; i < 100000; i++)
    {
        long long num = i * i;
        string key = to_string(num);
        if (key.find('0') != string::npos)
        {
            continue;
        }
        sort(key.begin(), key.end());
        data[key].push_back(num);
    }
    string n;
    while (cin >> n)
    {
        sort(n.begin(), n.end());
        try
        {
            for (const auto &item : data.at(n))
            {
                cout << item << ' ';
            }
            cout << '\n';
        }
        catch (const std::out_of_range &e)
        {
            cout << "0\n";
        }
    }
}
