#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    constexpr int kTargetCount = 1500;
    std::vector<int> ugly = {1};
    ugly.reserve(kTargetCount);
    int i2 = 0, i3 = 0, i5 = 0;
    while (ugly.size() < kTargetCount) {
        while (ugly.back() >= ugly[i2] * 2) ++i2;
        while (ugly.back() >= ugly[i3] * 3) ++i3;
        while (ugly.back() >= ugly[i5] * 5) ++i5;
        ugly.push_back(std::min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5}));
    }
    std::cout << "The 1500'th ugly number is " << ugly[kTargetCount - 1] << ".\n";
}
