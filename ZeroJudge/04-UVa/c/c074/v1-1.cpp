#include <iostream>
#include <vector>

void Combination(const std::vector<int>& arr, std::vector<int>& res, int idx = 0,
                 const int target_length = 6) {
    if (res.size() == target_length) {
        for (int i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
        }
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        res.push_back(arr[i]);
        Combination(arr, res, i + 1);
        res.pop_back();
    }
}

int main() {
    bool is_first_case = true;
    int n;
    while (std::cin >> n && n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        if (!is_first_case) {
            std::cout << '\n';
        }
        is_first_case = false;
        std::vector<int> res;
        res.reserve(n);
        Combination(arr, res);
    }
}
