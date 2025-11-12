#include <iostream>
#include <vector>
using namespace std;

int SQR(int n)
{
    return n * n;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n, {0, 0});
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].first >> points[i].second;
    }

    int max_len = 0;
    pair<int, int> result = {0, 0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp = SQR(points[i].first - points[j].first) + SQR(points[i].second - points[j].second);
            if (tmp > max_len)
            {
                max_len = tmp;
                result = {i, j};
            }
        }
    }
    cout << result.first << ' ' << result.second;
}
