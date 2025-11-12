#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int kLimit = 10000;
    const int kMod = 1000000007;
    vector<int> arr(kLimit + 1, 1);
    for (int i = 2; i < kLimit; ++i)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % kMod;
    }

    int n;
    while (cin >> n)
    {
        cout << arr[n] << '\n';
    }
}
