#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int depth = ceil(sqrt(n));
        int mid = (depth - 1) * (depth - 1) + depth;
        int row = depth;
        int col = depth - abs(mid - n);
        if (n > mid) {
            swap(row, col);
        }
        if (depth & 1) {
            swap(row, col);
        }
        cout << col << ' ' << row << '\n';
    }
}
