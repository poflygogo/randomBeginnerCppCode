// ZeroJudge c462
// APCS 2017-10 2 交錯字串 (Alternating Strings)
// C++14

#include <algorithm>  // max
#include <cctype>     // isupper
#include <cstddef>    // size_t
#include <iostream>
#include <string>
#include <vector>

int main() {
    int k;
    std::string s;
    std::cin >> k >> s;

    // find all segments
    std::vector<int> arr;
    bool is_upper = (bool)std::isupper(s.front());
    size_t idx = 0;
    for (size_t i = 1 /* start from index 1 */; i < s.size(); ++i) {
        if (is_upper != (bool)std::isupper(s[i])) {
            arr.push_back(i - idx);
            idx = i;
            is_upper = !is_upper;
        }
    }
    arr.push_back(s.size() - idx);

    // find max chain
    int max_chain = 0;
    int cnt = 0;
    for (int i : arr) {
        if (i < k) {
            max_chain = std::max(max_chain, cnt);
            cnt = 0;
        } else if (i > k) {
            cnt += k;
            max_chain = std::max(max_chain, cnt);
            cnt = k;
        } else if (i == k) {
            cnt += k;
        }
    }
    max_chain = std::max(max_chain, cnt);

    std::cout << max_chain << '\n';
}
