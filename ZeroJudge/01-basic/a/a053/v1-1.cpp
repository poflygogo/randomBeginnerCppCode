#include <iostream>
using namespace std;

int main()
{
    int n;
    int score = 0;
    cin >> n;
    if (n >= 0)
    {
        score += 6 * (n > 10 ? 10 : n);
    }
    if (n > 10)
    {
        score += 2 * (n > 20 ? 10 : n - 10);
    }
    if (n > 20)
    {
        score += n - 20;
    }
    if (n > 40)
    {
        score = 100;
    }
    cout << score << endl;
}