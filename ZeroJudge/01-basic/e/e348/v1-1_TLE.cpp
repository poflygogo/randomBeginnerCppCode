#include <iostream>

void replace(std::string &s, const std::string &old_str, const std::string &new_str)
{
    if (old_str.empty())
    {
        return;
    }
    int pos;
    while ((pos = s.find(old_str, pos)) != std::string::npos)
    {
        s.replace(pos, old_str.size(), new_str);
        pos += new_str.size();
    }
}

int main()
{
    std::string a, b;
    while (std::cin >> a >> b)
    {
        if (a + b != b + a)
        {
            std::cout << "= =\n";
        }
        else
        {
            while (!a.empty())
            {
                std::swap(a, b);
                replace(b, a, "");
            }
            std::cout << b << '\n';
        }
    }
}
