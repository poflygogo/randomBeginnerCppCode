#include <iostream>
#include <string>

std::string Repeat(const std::string &s, int time)
{
    std::string result;
    result.reserve(s.size() * time);
    while (time--)
    {
        result += s;
    }
    return result;
}

int main()
{
    int o_width, o_thick;
    int r_width, r_thick;
    char o, r;
    int n;
    std::string s;
    while (std::cin >> o_width >> o_thick >> r_width >> r_thick >> o >> r >> n)
    {
        int gap = std::abs(o_width - r_width) / 2;
        std::string cookie = std::string(gap * (o_width < r_width), ' ') + std::string(o_width, o) + '\n';
        cookie = Repeat(cookie, o_thick);
        std::string butter = std::string(gap * (o_width > r_width), ' ') + std::string(r_width, r) + '\n';
        butter = Repeat(butter, r_thick);
        while (n--)
        {
            std::cin >> s;
            for (int i = 0; i < s.size(); i += (s[i] == 'O' ? 1 : 2))
            {
                switch (s[i])
                {
                case 'O':
                    std::cout << cookie;
                    break;
                case 'R':
                    std::cout << butter;
                    break;
                default:
                    break;
                }
            }
            std::cout << '\n';
        }
    }
}
