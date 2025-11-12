#include <iostream>
#include <map>
#include <set>

int count_different_items(const std::string &s)
{
    std::set<char> t;
    for (int i = 0; i < s.size(); i++)
    {
        t.insert(s[i]);
    }
    return t.size();
}

int main()
{
    std::map<char, int> employee;
    std::string s;
    std::cin >> s;
    int k = count_different_items(s);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (!employee.count(s[i]))
        {
            employee[s[i]] = k;
            k--;
            if (k == 0)
            {
                break;
            }
        }
    }

    for (auto &&i : employee)
    {
        std::cout << i.second;
    }
}
