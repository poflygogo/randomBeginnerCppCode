#include <iostream>
#include <stack>

int main()
{
    std::string token;
    std::stack<std::string> expr;
    std::stack<int> calc;
    while (std::cin >> token)
    {
        expr.push(token);
    }
    while (!expr.empty())
    {
        token = expr.top();
        expr.pop();
        if (token == "f")
        {
            int x = calc.top();
            calc.pop();
            calc.push(2 * x - 3);
        }
        else if (token == "g")
        {
            int x = calc.top();
            calc.pop();
            int y = calc.top();
            calc.pop();
            calc.push(2 * x + y - 7);
        }
        else if (token == "h")
        {
            int x = calc.top();
            calc.pop();
            int y = calc.top();
            calc.pop();
            int z = calc.top();
            calc.pop();
            calc.push(3 * x - 2 * y + z);
        }
        else
        {
            calc.push(std::stoi(token));
        }
    }
    std::cout << calc.top();
}
