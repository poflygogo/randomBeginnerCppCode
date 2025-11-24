#include <iostream>
#include <unordered_set>
#include <vector>

bool is_b2_sequence(std::vector<int>& arr) {
    if (arr.front() < 1) {
        return false;
    }

    // check if the sequence is increasing
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }

    // check if the sequence is a B2-Sequence
    std::unordered_set<int> seen;
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i; j < arr.size(); ++j) {
            int sum = arr[i] + arr[j];
            if (seen.count(sum)) {
                return false;
            }
            seen.insert(sum);
        }
    }
    return true;
}

int main() {
    int test_cases = 1;
    int n;
    while (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::cout << "Case #" << test_cases << ": It is " << (is_b2_sequence(arr) ? "" : "not ")
                  << "a B2-Sequence.\n\n";
        test_cases++;
    }
}
