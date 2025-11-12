#include <iostream>
using namespace std;

int main()
{
    // --------------------------------
    // IO 優化......
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    short n;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> c;
            if (i == j)
            {
                cout << c;
            }
        }
    }
}
