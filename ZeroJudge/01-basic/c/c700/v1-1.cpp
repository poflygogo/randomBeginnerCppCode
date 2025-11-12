#include <iostream>
using namespace std;

int main()
{
    long long stack1 = 0;
    long long stack2 = 0;
    string s, res = "";
    while (cin >> s)
    {
        if (s == "push")
        {
            cin.ignore(10, '\n');
            res += '1';
            stack1++;
        }
        else if (s == "pop")
        {
            if (stack2)
            {
                res += '4';
                stack2--;
            }
            else
            {
                res += string(stack1, '5');
                res += '4';
                stack2 = stack1 - 1;
                stack1 = 0;
            }
        }
    }
    cout << res;
}
