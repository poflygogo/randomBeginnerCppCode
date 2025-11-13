#include <array>
#include <iostream>

using namespace std;

int main() {
    constexpr int kLimitSize = 19;
    array<array<int, kLimitSize>, kLimitSize> graph = {};

    {  // initialize
        int val = kLimitSize * kLimitSize - 1;
        int offset = kLimitSize - 1;
        size_t r = kLimitSize - 1;
        size_t c = r;
        while (offset > 0) {
            for (int i = 0; i < offset; i++) graph[r][c--] = val--;
            for (int i = 0; i < offset; i++) graph[r--][c] = val--;
            for (int i = 0; i < offset; i++) graph[r][c++] = val--;
            for (int i = 0; i < offset; i++) graph[r++][c] = val--;
            offset -= 2;
            r--;
            c--;
        }
    }

    const int mid = kLimitSize / 2;
    int n;
    while (cin >> n) {
        int offset = n / 2;
        size_t lower = mid - offset;
        size_t upper = mid + offset;
        for (size_t r = lower; r <= upper; r++) {
            for (size_t c = lower; c <= upper; c++) {
                cout.width(4);
                cout << graph[r][c];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
