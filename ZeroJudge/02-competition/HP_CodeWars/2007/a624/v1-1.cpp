#include <array>
#include <iostream>

using namespace std;

int main() {
    const array<string, 4> result_text = {"WEAK", "ACCEPTABLE", "GOOD", "STRONG"};
    string s;
    s.reserve(30);
    while (cin >> s) {
        bool has_upper = false;
        bool has_lower = false;
        bool has_num_or_sym = false;
        for (auto&& c : s) {
            has_upper |= isupper(c);
            if (isupper(c)) {
                has_upper = true;
            }
            if (islower(c)) {
                has_lower = true;
            }
            if (!isupper(c) && !islower(c)) {
                has_num_or_sym = true;
            }
        }

        int score = 0;
        score += (s.size() >= 8);
        score += (has_upper && has_lower);
        score += ((has_upper || has_lower) && has_num_or_sym);

        cout << "This password is " << result_text[score] << '\n';
    }
}
