#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> arr;
    std::string s;
    while (std::cin >> s)
    {
        arr.push_back(s);
    }
    std::cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        std::cout << " little, " << arr[i];
    }
    std::cout << " little Indians";
}
