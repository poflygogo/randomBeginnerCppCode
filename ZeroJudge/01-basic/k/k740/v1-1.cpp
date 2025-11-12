#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr1 = {1};
    std::cout << "1\n";
    for (int cnt = 2; cnt <= n; cnt++)
    {
        std::vector<int> arr2(cnt);
        arr2.front() = 1;
        arr2.back() = 1;
        for (int i = 1; i < arr1.size(); i++)
        {
            arr2[i] = arr1[i - 1] + arr1[i];
        }

        std::copy(arr2.begin(), arr2.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';

        arr1 = arr2;
    }
}
