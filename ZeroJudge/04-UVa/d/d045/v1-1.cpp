#include <array>
#include <iostream>
#include <set>

using namespace std;

int main() {
    constexpr int kTotalFriends = 3;
    // friends_info: 儲存每個人原本解出的題目
    // friends_info_diff: 用來計算每個人「唯一」解出的題目 (初始值等於 friends_info)
    array<set<int>, kTotalFriends> friends_info, friends_info_diff;
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        // 讀取每位朋友的解題資訊，順便初始化 friends_info_diff
        for (size_t i = 0; i < kTotalFriends; ++i) {
            friends_info[i].clear();
            friends_info_diff[i].clear();
            int solve_cnt;
            cin >> solve_cnt;
            while (solve_cnt--) {
                int solve_id;
                cin >> solve_id;
                friends_info[i].insert(solve_id);
            }
            // 先複製一份完整的清單，稍後再從中移除別人也解過的題目
            friends_info_diff[i] = friends_info[i];
        }

        int max_cnt = 0;
        // 計算每個人唯一解出的題目
        for (size_t i = 0; i < kTotalFriends; ++i) {
            set<int>& f = friends_info_diff[i];
            for (size_t j = 0; j < kTotalFriends; ++j) {
                if (i == j) continue;  // 跳過自己
                // 遍歷其他朋友解過的題目，並從目前這位朋友的清單中移除
                // 這樣剩下的就只會是「只有他自己解出來」的題目
                for (int val : friends_info[j]) {
                    f.erase(val);
                }
            }
            // 記錄目前為止最多的唯一解題數
            max_cnt = max(max_cnt, (int)f.size());
        }

        cout << "Case #" << test_case << ":\n";
        for (size_t i = 0; i < kTotalFriends; ++i) {
            if (friends_info_diff[i].size() != max_cnt) {
                continue;
            }
            cout << i + 1 << ' ' << max_cnt;
            for (int solve_id : friends_info_diff[i]) {
                cout << ' ' << solve_id;
            }
            cout << '\n';
        }
    }
}
