#include <iostream>
#include <vector>

int main()
{
    int length, cnt;
    std::cin >> length;
    std::vector<std::string> cards(length);
    for (int i = 0; i < length; i++)
    {
        std::cin >> cards[i];
    }
    std::cin >> cnt;

    for (int i = cnt; i < length; i++)
    {
        std::cout << cards[i] << ' ';
    }
    for (int i = 0; i < cnt; i++)
    {
        std::cout << cards[i] << (i < cnt - 1 ? ' ' : '\n');
    }
}
