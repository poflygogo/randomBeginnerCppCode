#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------
    
    int n, size, cnt, tmp;
    cin >> n >> size;
    set<int> nums1;
    set<int> nums2;
    vector<int> res;
    while (n--)
    {
        for (int i = 0; i < size; i++)
        {
            cin >> tmp;
            nums1.insert(tmp);
        }
        for (int i = 0; i < size; i++)
        {
            cin >> tmp;
            nums2.insert(tmp);
        }
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                         back_inserter(res));
        cout << res.size() << '\n';
        nums1.clear();
        nums2.clear();
        res.clear();
    }
}
