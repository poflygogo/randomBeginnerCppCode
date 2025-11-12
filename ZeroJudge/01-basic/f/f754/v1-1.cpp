#include <iostream>

int main()
{
    // --------------------------------
    // 不是很重要的 IO 優化......
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // --------------------------------
    
    int n;
    long long a, b, avg;
    std::cin >> n;
    for (int case_cnt = 1; case_cnt <= n; case_cnt++)
    {
        std::cin >> a >> b;
        avg = a / b;
        std::cout << "Case " << case_cnt << " :\n";
        for (long long i = 1; i < b; i++)
        {
            std::cout << "第" << i << "位 : 拿" << avg << "元並說DD! BAD!\n";
        }
        std::cout << "第" << b << "位 : 拿" << a - avg * (b - 1) << "元並說DD! BAD!\n";
    }
}
