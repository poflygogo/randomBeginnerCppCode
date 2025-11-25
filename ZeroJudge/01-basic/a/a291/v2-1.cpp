#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

istream& operator>>(istream& is, vector<int>& arr) {
    for (auto& x : arr) is >> x;
    return is;
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
            vector<int> secret_copy = secret;

            int a = 0;
            int b = 0;
            for (size_t i = 0; i < kSize; ++i) {
                if (secret_copy[i] == guess[i]) {
                    ++a;
                    secret_copy[i] = -1;
                    guess[i] = -1;
                }
            }
            for (size_t i = 0; i < kSize; ++i) {
                if (guess[i] != -1) {
                    auto it = find(secret_copy.begin(), secret_copy.end(), guess[i]);
                    if (it != secret_copy.end()) {
                        ++b;
                        *it = -1;
                    }
                }
            }
            cout << a << 'A' << b << 'B' << '\n';
        }
    }
}
