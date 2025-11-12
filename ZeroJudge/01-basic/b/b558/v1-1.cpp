#include <array>
#include <iostream>
using namespace std;

int main() {
    const int kLimit = 500;
    array<int, kLimit> arr = {0};
    arr[0] = 1;
    for (int i = 1; i < kLimit; ++i) {
        arr[i] += arr[i - 1] + i;
    }

    int n;
    while (cin >> n) {
        cout << arr[n - 1] << '\n';
    }
}
