#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> in_time(n), ex_time(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> in_time[i] >> ex_time[i];
    }
    std::sort(in_time.begin(), in_time.end());
    std::sort(ex_time.begin(), ex_time.end());

    int viewer = 0;
    int max_viewer = viewer;
    int idx = 0;
    for (auto &&i : in_time)
    {
        viewer++;
        if (ex_time[idx] < i)
        {
            viewer--;
            idx++;
        }
        max_viewer = std::max(max_viewer, viewer);
    }
    std::cout << max_viewer;
}
