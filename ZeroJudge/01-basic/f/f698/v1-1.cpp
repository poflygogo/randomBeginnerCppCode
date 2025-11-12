#include <iostream>
#include <stack>

int main()
{
    const std::string op = "+-*/";
    std::stack<int> st;
    std::string item;
    while (std::cin >> item)
    {
        if (op.find(item) == std::string::npos)
        {
            st.push(std::stoi(item));
            continue;
        }

        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (item == "+")
        {
            st.push(a + b);
        }
        else if (item == "-")
        {
            st.push(b - a);
        }
        else if (item == "*")
        {
            st.push(a * b);
        }
        else if (item == "/")
        {
            st.push(b / a);
        }
        else
        { // should not happen
            std::cout << "wtf is \"" << item << "\"???";
            return 0;
        }
    }
    std::cout << st.top();
}
