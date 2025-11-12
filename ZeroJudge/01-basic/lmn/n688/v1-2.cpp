#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int sum(const std::vector<int>& arr) { 
    return std::accumulate(arr.begin(), arr.end(), 0); 
}

int sum(const std::vector<int>& arr, const int start, const int end) {
    return std::accumulate(arr.begin() + start, arr.begin() + end, 0);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> positive, negative;
    positive.reserve(n);
    negative.reserve(n);

    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        if (tmp < 0) {
            negative.push_back(tmp);
        } else {
            positive.push_back(tmp);
        }
    }
    std::sort(positive.begin(), positive.end());
    std::sort(negative.begin(), negative.end());

    if (k <= negative.size()) {
        std::cout << sum(positive) - sum(negative, 0, k) + sum(negative, k, negative.size());
    } else {
        if ((k - negative.size()) % 2 == 0) {
            std::cout << sum(positive) - sum(negative);
        } else if (!negative.empty()) {
            if (-negative.back() < positive.front()) {
                std::cout << sum(positive) - sum(negative, 0, negative.size() - 1) +
                                 negative.back();
            } else {
                std::cout << sum(positive, 1, positive.size()) - positive.front() - sum(negative);
            }
        } else {
            std::cout << sum(positive, 1, positive.size()) - positive.front();
        }
    }
}
