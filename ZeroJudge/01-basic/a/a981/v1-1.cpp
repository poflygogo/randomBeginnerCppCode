#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool g_flag = false; // 標示是否有輸出過任何內容

/**
 * @brief 窮舉 arr 所有中所有相加為 target 的數字組合並輸出
 * @param target 目標整數
 * @param arr 可用的元素
 * @param path 當前使用的元素
 * @param curr_sum path 中所有元素的總和
 * @param start_idx 要從哪裡開始遍歷 arr
 */
void Solution(const int &target, const vector<int> &arr, vector<int> &path, int &curr_sum, int start_idx = 0) {
    if (target == curr_sum) {
        for (const int &item : path) {
            cout << item << " ";
        }
        cout << '\n';
        g_flag = true;
        return;
    } else if (target < curr_sum) { // 理論上不該發生，但還是留著
        return;
    } else {
        for (int i = start_idx; i < arr.size(); i++) {
            if (curr_sum + arr[i] >
                target) { // arr 是有序排列的，如果加上目前的數字就已經會超過 target
                break;    // 那後面所有數字都一定也會超過，就不需要再考慮他們了
            }
            curr_sum += arr[i];
            path.push_back(arr[i]);
            Solution(target, arr, path, curr_sum, i + 1);
            curr_sum -= arr[i];
            path.pop_back();
        }
    }
}

/**
 * @brief 窮舉 arr 所有中所有相加為 target 的數字組合並輸出
 *
 * 這只是一個用來簡化邏輯的接口，這樣就不需要在 main 裡面初始化一些預設值了。
 * 例如不應該設定成函式預設值的 std::vector
 *
 * @param target 目標整數
 * @param arr 可用的元素
 */
void Solution(const int &target, vector<int> &arr) {
    int curr_sum = 0;
    vector<int> result;
    sort(arr.begin(), arr.end()); // 目標是根據字典序輸出結果
    Solution(target, arr, result, curr_sum);
    if (!g_flag) {
        cout << "-1\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution(m, arr);
}
