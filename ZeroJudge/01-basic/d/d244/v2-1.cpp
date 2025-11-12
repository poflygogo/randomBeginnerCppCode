#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> arr;
    while (cin >> n)
    {
        arr.push_back(n);
    }
    sort(arr.begin(), arr.end());
    for (int i = 2; i < arr.size(); i += 3)
    {
        if (arr[i] != arr[i - 2])
        {
            cout << arr[i - 2];
            return 0;
        }
    }
}
