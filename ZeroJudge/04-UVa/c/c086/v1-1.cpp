#include <array>
#include <iostream>
#include <numeric>  // iota
#include <vector>

using namespace std;

int main() {
    constexpr int kTotalCards = 20;
    array<int, kTotalCards> cards;
    int test_case = 1;
    int n, x;
    while (cin >> n >> x) {
        for (int i = 0; i < kTotalCards; i++) {
            cin >> cards[i];
        }
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);

        int idx = 0;
        while (arr.size() > x && idx < kTotalCards) {
            int step = cards[idx++] - 1;  // 這個 -1 是靈魂
            for (auto it = arr.begin() + step; it < arr.end() && arr.size() > x; it += step) {
                arr.erase(it);
            }
        }

        cout << "Selection #" << test_case++ << '\n';
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i + 1 < arr.size() ? " " : "\n\n");
        }
    }
}
