#include <iostream>

int Base9ToInt(const std::string &num_9base)
{
    int res = 0;
    for (char c : num_9base)
    {
        res *= 26;
        res += c - 'A' + 1;
    }
    return res;
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    std::cout << Base9ToInt(b) - Base9ToInt(a) + 1;
}
