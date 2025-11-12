#include <algorithm> // std::find
#include <climits>   // INT_MAX
#include <iostream>
#include <map>
#include <sstream> // std::istringstream
#include <vector>

int main()
{
    std::vector<std::string> items;
    std::map<std::string, int> Counter;
    std::istringstream iss;
    std::string s;

    std::getline(std::cin, s);
    iss.str(s);
    while (iss >> s)
    {
        items.push_back(s);
    }

    std::getline(std::cin, s);
    iss.clear();
    iss.str(s);
    while (iss >> s)
    {
        if (std::find(items.begin(), items.end(), s) != items.begin())
        {
            Counter[s] += 1;
        }
    }

    int res = INT_MAX;
    for (const std::pair<std::string, int> &item : Counter)
    {
        if (item.second < res)
        {
            res = item.second;
        }
    }
    std::cout << (res == INT_MAX ? 0 : res);
}
