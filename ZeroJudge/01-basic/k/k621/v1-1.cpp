#include <iostream>
#include <map>
#include <stack>

bool Solve()
{
    const std::string tokens = "()[]";
    const std::map<char, char> match = {{')', '('}, {']', '['}};
    std::stack<char> st;
    char c;
    while (std::cin.get(c) && tokens.find(c) != std::string::npos)
    {
        if (c == '[' || c == '(')
        {
            st.push(c);
        }
        else if (!st.empty() && st.top() == match.at(c))
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}

int main()
{
    std::cout << (Solve() ? "Right" : "Wrong");
}
