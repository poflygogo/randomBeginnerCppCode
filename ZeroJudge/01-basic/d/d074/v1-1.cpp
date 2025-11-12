#include <iostream>
using namespace std;

int main()
{
    int n, stu, res = 0;
    cin >> n;
    while (n--)
    {
        cin >> stu;
        if (stu > res)
        {
            res = stu;
        }
    }
    cout << res;
}
