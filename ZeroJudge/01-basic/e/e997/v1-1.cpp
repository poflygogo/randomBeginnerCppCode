#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> arr;
    std::istringstream iss;
    std::string s;
    int n;
    std::getline(std::cin, s);
    iss.str(s);
    while (iss >> s)
    {
        arr.push_back(s);
    }
    std::cin >> n;
    std::cout << arr[arr.size() - n];
}
