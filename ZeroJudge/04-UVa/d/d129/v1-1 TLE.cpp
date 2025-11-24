#include <iostream>

bool is_ugly(int val) {
    static constexpr int kPrimes[] = {2, 3, 5};
    for (const auto p : kPrimes) {
        while (val % p == 0) {
            val /= p;
        }
    }
    return val == 1;
}

int main() {
    constexpr int kTargetCount = 1500;
    int curr_count = 1;
    int val = 0;
    while (curr_count < kTargetCount) {
        ++val;
        if (is_ugly(val)) {
            ++curr_count;
        }
    }
    std::cout << val << '\n';
}
