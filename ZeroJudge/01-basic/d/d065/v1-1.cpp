#include <iostream>
using namespace std;

int main()
{
    int num, max_val = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        if (num > max_val)
        {
            max_val = num;
        }
    }
    cout << max_val;
}
