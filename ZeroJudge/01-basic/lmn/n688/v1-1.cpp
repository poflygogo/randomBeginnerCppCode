#include <algorithm>
#include <iostream>
#include <vector>

int sum(const std::vector<int>& arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res += arr[i];
    }
    return res;
}

int sum(const std::vector<int>& arr, const int start, const int end) {
    int res = 0;
    for (int i = start; i < end; i++) {
        res += arr[i];
    }
    return res;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr_plus, arr_minus;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        if (tmp < 0) {
            arr_minus.push_back(tmp);
        } else {
            arr_plus.push_back(tmp);
        }
    }
    std::sort(arr_plus.begin(), arr_plus.end());
    std::sort(arr_minus.begin(), arr_minus.end());

    if (k <= arr_minus.size()) {
        std::cout << sum(arr_plus) - sum(arr_minus, 0, k) + sum(arr_minus, k, arr_minus.size());
    } else {
        if ((k - arr_minus.size()) % 2 == 0) {
            std::cout << sum(arr_plus) - sum(arr_minus);
        } else if (!arr_minus.empty()) {
            if (-arr_minus.back() < arr_plus.front()) {
                std::cout << sum(arr_plus) - sum(arr_minus, 0, arr_minus.size() - 1) + arr_minus.back();
            } else {
                std::cout << sum(arr_plus, 1, arr_plus.size()) - arr_plus.front() - sum(arr_minus);
            }
        } else {
            std::cout << sum(arr_plus, 1, arr_plus.size()) - arr_plus.front();
        }
    }
}
