#include <iostream>
#include <unordered_map>

void Combination(std::unordered_map<std::string, int>& nums, std::string& res, const int target) {
    static int cnt = 1;
    if (res.size() == target) {
        nums[res] = cnt++;
        return;
    }
    for (char i = (res.empty() ? 'a' : res.back() + 1); i <= 'z'; i++) {
        res += i;
        Combination(nums, res, target);
        res.pop_back();
    }
}

int main() {
    std::unordered_map<std::string, int> nums;
    nums.reserve(83681);
    std::string s = "";
    s.reserve(5);
    Combination(nums, s, 1);
    Combination(nums, s, 2);
    Combination(nums, s, 3);
    Combination(nums, s, 4);
    Combination(nums, s, 5);

    while (std::cin >> s) {
        if (nums.find(s) != nums.end()) {
            std::cout << nums.at(s) << '\n';
        } else {
            std::cout << "0\n";
        }
    }
}
