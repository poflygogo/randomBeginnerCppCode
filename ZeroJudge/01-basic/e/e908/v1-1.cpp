#include <array>
#include <iostream>

const std::array<std::string, 7> weekdays = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                             "Friday", "Saturday", "Sunday"};

int main()
{
    std::string s;
    unsigned int n, idx;
    std::cin >> s >> n;
    for (int i = 0; i < 7; i++)
    {
        if (weekdays[i] == s)
        {
            idx = i;
            break;
        }
    }

    std::cout << weekdays[(idx + n) % 7];
}
