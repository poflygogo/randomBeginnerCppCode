#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

template <size_t N>
istream& operator>>(istream& is, array<int, N>& arr) {
    for (auto& x : arr) is >> x;
    return is;
}

int main() {
    constexpr int kSize = 4;
    constexpr int kDigitRange = 10;

    array<int, kSize> secret;
    array<int, kSize> guess;

    while (cin >> secret) {
        array<int, kDigitRange> secret_freq{};
        for (int x : secret) secret_freq[x]++;

        int n;
        cin >> n;
        while (n--) {
            cin >> guess;

            int a = 0;
            array<int, kDigitRange> guess_freq{};

            // 單次遍歷同時計算 A 和 建立 guess 的頻率表
            for (size_t i = 0; i < kSize; ++i) {
                if (secret[i] == guess[i]) {
                    ++a;
                }
                guess_freq[guess[i]]++;
            }

            // 利用數學性質計算 B
            // 兩個陣列的「交集總數 (A+B)」 = 所有數字頻率最小值的總和
            int total_match = 0;
            for (int i = 0; i < kDigitRange; ++i) {
                total_match += min(secret_freq[i], guess_freq[i]);
            }

            int b = total_match - a;

            cout << a << 'A' << b << 'B' << '\n';
        }
    }
}