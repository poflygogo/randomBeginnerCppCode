#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    int cnt = 0;
    int n, y;
    string action;
    cin >> n;
    while (n--)
    {
        cin >> action;
        if (action == "L")
        {
            x--;
        }
        else if (action == "R")
        {
            x++;
        }
        else
        {
            cin >> y;
            cnt += (x == y);
        }
    }
    cout << cnt;
}
