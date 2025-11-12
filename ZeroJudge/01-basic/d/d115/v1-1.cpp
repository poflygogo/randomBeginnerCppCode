#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Combination(const int size, const vector<int> &nums, const int pick, vector<int> &res,
                 int curr = 0)
{
    if (res.size() == pick)
    {
        for (auto &&i : res)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = curr; i < size; ++i)
    {
        res.push_back(nums[i]);
        Combination(size, nums, pick, res, i + 1);
        res.pop_back();
    }
}

int main()
{
    int n, pick;
    vector<int> res;
    while (cin >> n && n)
    {
        vector<int> nums;
        nums.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> pick;
            nums.push_back(pick);
        }
        cin >> pick;
        sort(nums.begin(), nums.end());
        res.clear();
        res.reserve(n);
        Combination(n, nums, pick, res);
        cout << '\n';
    }
}
