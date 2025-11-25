#include <algorithm>  // all_of
#include <array>
#include <iostream>
#include <istream>  // operator>>, istream
#include <string>
#include <vector>

using namespace std;

// lazy cin :P
istream& operator>>(istream& is, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        is >> arr[i];
    }
    return is;
}

int main() {
    int game_cnt = 1;
    array<int, 10> secret_cnt;  // count of each number in secret
    array<int, 10> guess_cnt;   // count of each number in guess
    int length;
    while (cin >> length && length != 0) {
        cout << "Game " << game_cnt << ":\n";
        game_cnt++;

        secret_cnt.fill(0);
        vector<int> secret(length);
        for (int i = 0; i < length; i++) {
            cin >> secret[i];
            secret_cnt[secret[i]]++;
        }

        vector<int> guess(length);
        while (cin >> guess) {
            if (all_of(guess.begin(), guess.end(), [](int x) { return x == 0; })) {
                break;
            }
            guess_cnt.fill(0);

            // count of each number in guess and a
            int a = 0;
            for (int i = 0; i < length; i++) {
                if (secret[i] == guess[i]) {
                    a++;
                }
                guess_cnt[guess[i]]++;
            }

            // calculate intersection of secret_cnt and guess_cnt
            int total_match = 0;
            for (int i = 0; i < 10; i++) {
                total_match += min(secret_cnt[i], guess_cnt[i]);
            }
            int b = total_match - a;

            cout << string(4, ' ') << '(' << a << ',' << b << ")\n";
        }
    }
}
