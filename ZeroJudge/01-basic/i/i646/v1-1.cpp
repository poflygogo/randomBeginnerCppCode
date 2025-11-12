#include <iostream>
#include <numeric> // std::iota

void Permutation(std::string &tokens, std::string res = "")
{
    if (res.size() == tokens.size())
    {
        std::cout << res << '\n';
        res.pop_back();
        return;
    }

    for (char c : tokens)
    {
        if (res.find(c) == std::string::npos)
        {
            res += c;
            Permutation(tokens, res);
            res.pop_back();
        }
    }
}

int main()
{
    int n;
    while (std::cin >> n && n)
    {
        std::string s(n, 0);
        std::iota(s.begin(), s.end(), 'a');
        Permutation(s);
    }
}
