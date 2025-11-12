#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int ReverseInt(int n)
{
    int res = 0;
    while (n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        arr[i] = ReverseInt(arr[i]);
    }
    cout << *max_element(arr.begin(), arr.end()) << '\n';
}
