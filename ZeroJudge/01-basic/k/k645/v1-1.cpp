#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::vector<int> arr;

    while (std::getline(std::cin, s, '+'))
    {
        arr.push_back(std::stoi(s));
    }

    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << (i == arr.size() - 1 ? '\n' : '+');
    }
}
