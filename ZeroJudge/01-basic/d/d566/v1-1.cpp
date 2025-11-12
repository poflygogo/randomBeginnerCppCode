#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n;
    string name, score;
    unordered_map<string, bool> status;
    vector<pair<string, bool>> record;
    int total_ac = 0;
    int total_ac_instantly = 0;
    cin >> n;
    while (n--)
    {
        cin >> name >> score;
        record.push_back({name, (score == "AC")});
    }
    reverse(record.begin(), record.end());
    for (auto &[s, flag] : record)
    {
        if (status.find(s) == status.end())
        {
            if (flag)
            {
                total_ac++;
                total_ac_instantly++;
            }
            status[s] = flag;
        }
        else
        {
            total_ac += (!status[s] && flag);
            status[s] = (status[s] || flag);
        }
    }
    if (total_ac)
    {
        cout << total_ac_instantly * 100 / total_ac << '%';
    }
    else
    {
        cout << "0%";
    }
}
