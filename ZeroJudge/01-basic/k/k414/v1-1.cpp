#include <algorithm>
#include <array>
#include <iostream>

constexpr std::array<int, 31> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,  31,  37,  41,  43,  47, 53,
                                        59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};

void ReadDeckInfo(std::array<int, 16> &arr)
{
    for (int i = 0; i < 16; i++)
    {
        std::cin >> arr[i];
    }
}

int main()
{
    std::array<std::array<int, 16>, 5> deck;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            std::cin >> deck[i][j];
        }
    }

    std::array<std::pair<int, int>, 31> res;
    int res_idx = 0;
    for (auto &&p : primes)
    {
        std::string tmp(5, '0');
        for (int i = 0; i < 5; i++)
        {
            if (std::find(deck[i].begin(), deck[i].end(), p) != deck[i].end())
            {
                tmp[i] = '1';
            }
        }
        res[res_idx] = {std::stoi(tmp, nullptr, 2), p};
        res_idx++;
    }

    std::sort(res.begin(), res.end());
    for (auto &&i : res)
    {
        std::cout << i.second << ' ';
    }
}
