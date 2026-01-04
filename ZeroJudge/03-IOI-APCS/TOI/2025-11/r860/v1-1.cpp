// ZeroJudge r860
// TOI 練習賽 新手組 第三題 符文 (Runes)
// C++14

#include <iostream>
#include <vector>

int find(const std::vector<int> &arr, const std::vector<int> &sub_arr) {
    for (size_t i = 0; i + sub_arr.size() < arr.size(); ++i) {
        bool flag = true;
        for (size_t j = 0; j < sub_arr.size(); ++j) {
            if (arr[i + j] != sub_arr[j]) {
                flag = false;
                break;
            }
        }

        if (flag) { return i + 1; }
    }

    return 0;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> arr(N);
    std::vector<int> sub_arr(M);

    for (auto &&i : arr) {
        std::cin >> i;
    }
    for (auto &&i : sub_arr) {
        std::cin >> i;
    }

    int res = find(arr, sub_arr);
    if (res) {
        std::cout << res;
    } else {
        std::cout << "not found";
    }
}
