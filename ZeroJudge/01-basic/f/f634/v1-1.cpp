#include <iomanip> // std::fix / std::setprecision
#include <iostream>
#include <map>
#include <set>

std::map<int, std::map<int, std::set<std::string>>> data = {
    {1, {{1, {}}, {2, {}}, {3, {}}}},
    {2, {{1, {}}, {2, {}}, {3, {}}}},
    {3, {{1, {}}, {2, {}}, {3, {}}}},
};

int TypeSum(int target)
{
    int sum = 0;
    for (auto &&i : data.at(target))
    {
        sum += i.second.size();
    }
    return sum;
}

int ClassSum(int target)
{
    int sum = 0;
    for (auto &&i : data)
    {
        sum += i.second.at(target).size();
    }
    return sum;
}

double SurvivalRate(int total)
{
    return (TypeSum(1) + TypeSum(2) + TypeSum(3)) * 100 / double(total);
}

int main()
{
    int n, m;
    std::string s;
    int a, b;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> s >> a >> b;
        data.at(a).at(b).insert(s);
    }

    std::cout << "navy:" << TypeSum(1) << ' '
              << "army:" << TypeSum(2) << ' '
              << "air:"  << TypeSum(3) << '\n'
              << "officer:"  << ClassSum(1) << ' '
              << "sergeant:" << ClassSum(2) << ' '
              << "soldier:"  << ClassSum(3) << '\n'
              << "survival rate: " << std::fixed << std::setprecision(1) << SurvivalRate(n) << '%';
}
