#include <iostream>

int main()
{
    std::string a_name, b_name;
    int a_score, b_score;
    std::cin >> a_name >> a_score >> b_name >> b_score;
    if (a_score > b_score)
    {
        std::cout << a_name << " WIN!";
    }
    else if (a_score < b_score)
    {
        std::cout << b_name << " WIN!";
    }
    else
    {
        std::cout << "tie";
    }
}
