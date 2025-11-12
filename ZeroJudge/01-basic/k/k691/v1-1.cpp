#include <algorithm>
#include <cmath>
#include <iostream>

int eval(std::string &expr)
{
    if (expr.front() == 's')
    {
        return (int)sqrt(std::stoi(expr.substr(5, expr.size())));
    }

    int a, b;
    std::string op;

    auto it1 = std::find_if(expr.begin(), expr.end(), [](char c) { return !std::isdigit(c); });
    int i = std::distance(expr.begin(), it1);
    a = std::stoi(expr.substr(0, i));

    auto it2 = std::find_if(it1, expr.end(), [](char c) { return std::isdigit(c); });
    int j = std::distance(expr.begin(), it2);
    op = expr.substr(i, j - i);
    b = std::stoi(expr.substr(j, expr.size()));

    if (op == "+")
    {
        return a + b;
    }
    else if (op == "-")
    {
        return a - b;
    }
    else if (op == "*")
    {
        return a * b;
    }
    else if (op == "/")
    {
        return a / b;
    }
    else if (op == "**")
    {
        return (int)pow(a, b);
    }

    throw std::invalid_argument("what is \"" + op + "\" ?");
}

int main()
{
    int t;
    std::string expr;
    std::cin >> t;
    std::cin.ignore();
    while (t--)
    {
        std::getline(std::cin, expr);
        std::cout << eval(expr) << '\n';
    }
}
