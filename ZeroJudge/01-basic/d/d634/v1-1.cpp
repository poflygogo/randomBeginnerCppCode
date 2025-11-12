#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<std::string> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, arr[i]);
    }
    std::sort(arr.begin(), arr.end());
    for (const std::string s : arr)
    {
        std::cout << s << '\n';
    }
}
