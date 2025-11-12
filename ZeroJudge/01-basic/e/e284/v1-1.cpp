#include <iostream>
#include <unordered_set>

const int kLimit = 31;
std::unordered_set<int> nums;

void Initialize()
{
    nums.reserve(31);
    int n = 1;
    for (int i = 0; i < kLimit; i++)
    {
        nums.insert(n);
        n <<= 1;
    }
}

int main()
{
    Initialize();

    // --------------------------------
    // 不是很重要的 IO 優化......嗎?
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------

    int n;
    while (std::cin >> n)
    {
        std::cout << (nums.find(n) != nums.end() ? "Yes" : "No") << '\n';
    }
}
