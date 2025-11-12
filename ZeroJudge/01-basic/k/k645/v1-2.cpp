#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::vector<int> arr;

    int n;
    while (std::cin >> n)
    {
        arr.push_back(n);
        if (std::cin.peek() == '+')
        {
            std::cin.ignore();
        }
    }

    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << (i == arr.size() - 1 ? '\n' : '+');
    }
}
