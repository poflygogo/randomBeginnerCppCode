#include <iostream>
#include <istream>
#include <unordered_map>
#include <vector>

using namespace std;
using Counter = unordered_map<int, int>;

istream& operator>>(istream& is, vector<int>& arr) {
    for (auto& x : arr) is >> x;
    return is;
}

Counter counter(const vector<int>& arr) {
    Counter cnt;
    for (auto x : arr) cnt[x]++;
    return cnt;
}

int main() {
    constexpr int kSize = 4;
    vector<int> secret(kSize);
    vector<int> guess(kSize);
    while (cin >> secret) {
        int n;
        cin >> n;
        while (n--) {
            cin >> guess;
            Counter secret_cnt = counter(secret);

            int a = 0;
            int b = 0;

            for (size_t i = 0; i < kSize; ++i) {
                if (secret[i] == guess[i]) {
                    ++a;
                    secret_cnt[secret[i]]--;
                }
            }
            for (size_t i = 0; i < kSize; ++i) {
                if (secret[i] != guess[i] && secret_cnt.count(guess[i]) && secret_cnt[guess[i]] > 0) {
                    ++b;
                    secret_cnt[guess[i]]--;
                }
            }
            cout << a << 'A' << b << 'B' << '\n';
        }
    }
}
