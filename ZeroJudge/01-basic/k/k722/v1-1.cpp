#include <iostream>
#include <set>

int main()
{
    const std::string result_yu = "�ΧE"; // 這她媽三小啦???
    const std::string result_li = "肥李";
    const std::string result_eq = "打平";

    const std::set<std::string> win = {"AB", "BC", "CA"};

    std::string a, b;
    int score_a = 0;
    int score_b = 0;
    while (std::cin >> a >> b)
    {
        if (a == b)
        {
            continue;
        }
        else if (win.count(a + b))
        {
            score_b++;
        }
        else
        {
            score_a++;
        }
    }

    std::cout << score_a << '\n' << score_b << '\n';
    if (score_a > score_b)
    {
        std::cout << result_yu;
    }
    else if (score_a < score_b)
    {
        std::cout << result_li;
    }
    else
    {
        std::cout << result_eq;
    }
}
