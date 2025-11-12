#include <iostream>
using namespace std;
#define SPACE " "

int main()
{
    unsigned int t;
    const unsigned int SIZE = 5;
    int arr[SIZE];
    cin >> t;
    while (t--)
    {
        for (unsigned int i = 0; i < SIZE - 1; i++)
        {
            cin >> arr[i];
        }
        if (arr[1] - arr[0] == arr[2] - arr[1])
        {
            arr[4] = arr[3] * 2 - arr[2];
        }
        else
        {
            arr[4] = arr[3] * arr[3] / arr[2];
        }
        for (unsigned int i = 0; i < SIZE - 1; i++)
        {
            cout << arr[i] << SPACE;
        }
        cout << arr[4] << endl;
    }
    return 0;
}
