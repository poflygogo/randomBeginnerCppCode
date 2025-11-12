#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> arr;
    std::string s;
    while (std::cin >> s)
    {
        arr.push_back(s);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < arr.size(); j += 3)
        {
            std::cout << (j == i ? "" : " ") << arr[j];
        }
        std::cout << '\n';
    }
}
