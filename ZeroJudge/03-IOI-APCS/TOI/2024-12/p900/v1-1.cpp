#include <array>
#include <climits>  // INT_MAX
#include <iostream>

using namespace std;

int main() {
    constexpr int kDays = 10;
    array<int, kDays> outboard, inboard;
    for (size_t i = 0; i < kDays; i++) {
        cin >> outboard[i];
    }
    for (size_t i = 0; i < kDays; i++) {
        cin >> inboard[i];
    }

    int start, end;
    int min_cost = INT_MAX;
    for (int i = 0; i < kDays; i++) {
        for (int j = i; j < kDays; j++) {
            int tmp = outboard[i] + inboard[j] + 1000 * (j - i);
            if (tmp < min_cost) {
                start = i;
                end = j;
                min_cost = tmp;
            }
        }
    }

    start++;
    end++;
    std::cout << start << ' ' << end << ' ' << min_cost;
}
