#include <iostream>
#include <numeric> // std::iota

void Combination(const std::string &tokens, const int take, std::string res = "", int curr_idx = 0)
{
    if (res.size() == take)
    {
        std::cout << res << '\n';
        res.pop_back();
        return;
    }

    for (int i = curr_idx; i < tokens.size(); i++)
    {
        if (res.find(tokens[i]) == std::string::npos)
        {
            res += tokens[i];
            Combination(tokens, take, res, i + 1);
            res.pop_back();
        }
    }
}

int main()
{
    int n, m;
    while (std::cin >> n >> m && n && m)
    {
        std::string s(n, 0);
        std::iota(s.begin(), s.end(), 'a');
        Combination(s, m);
    }
}
