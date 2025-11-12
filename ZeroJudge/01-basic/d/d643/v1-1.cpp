#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool flag = true;

void solve(const std::string s, int step)
{
    std::vector<std::string> arr;
    for (int i = 0; i < s.size(); i += step)
    {
        arr.push_back(s.substr(i, step));
    }
    std::sort(arr.begin(), arr.end());
    std::string res;
    for (int i = 0; i < arr.size(); i++)
    {
        res += arr[i];
    }
    if (res != s)
    {
        std::cout << res << '\n';
        flag = false;
    }
}

std::vector<int> Factorize(int n)
{
    if (n == 1)
    {
        return {};
    }
    std::vector<int> res = {1};
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
            {
                res.push_back(n / i);
            }
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

int main()
{
    std::string s;
    while (std::getline(std::cin, s))
    {
        std::vector<int> arr = Factorize(s.size());
        for (int i : arr)
        {
            solve(s, i);
        }
        if (flag)
        {
            std::cout << "bomb!\n";
        }
    }
}
