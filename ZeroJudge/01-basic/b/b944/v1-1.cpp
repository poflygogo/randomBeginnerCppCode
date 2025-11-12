#include <iostream>
#include <vector>
using namespace std;

bool FindToilet(vector<pair<int, int>> &toilet_info, int a, int b)
{
    for (int i = 0; i < toilet_info.size(); ++i)
    {
        // 不是空的小便斗就不用考慮了
        if (toilet_info[i].first != 0)
        {
            continue;
        }

        // aware edge case
        if ((i == 0 && toilet_info[1].first == 0) ||
            (i == toilet_info.size() - 1 && toilet_info[i - 1].first == 0) ||
            (toilet_info[i - 1].first == 0 && toilet_info[i + 1].first == 0))
        {
            toilet_info[i] = {a, b};
            return false;
        }
    }
    // 前一輪找不到好風水，隨便有空位就進去
    for (int i = 0; i < toilet_info.size(); ++i)
    {
        if (toilet_info[i].first == 0)
        {
            toilet_info[i] = {a, b};
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> toilet_info(n, {0, 0});  // <user_id, time>
    int a, b;
    while (cin >> a >> b)
    {
        // 先消耗使用時間，只要歸零或小於零的就重置
        for (pair<int, int> &toilet : toilet_info)
        {
            toilet.second = max(toilet.second - 1, 0);
            toilet.first = (toilet.second == 0 ? 0 : toilet.first);
        }

        // 找小便斗
        if (FindToilet(toilet_info, a, b))
        {
            cout << "Not enough\n";
        }

        // 輸出當前狀態
        cout << "Number: ";
        for (const pair<int, int> &toilet : toilet_info)
        {
            cout << toilet.first << ' ';
        }
        cout << "\n  Time: ";
        for (const pair<int, int> &toilet : toilet_info)
        {
            cout << toilet.second << ' ';
        }
        cout << "\n\n";
    }
}
