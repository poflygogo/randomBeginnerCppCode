#include <climits>
#include <iostream>

int main()
{
    int curr;
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    while (std::cin >> curr)
    {
        max_val = std::max(max_val, curr);
        min_val = std::min(min_val, curr);
    }
    std::cout << min_val << ' ' << max_val - min_val;
}
