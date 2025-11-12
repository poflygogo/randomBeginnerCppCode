#include <climits>
#include <iostream>

int main()
{
    int n, m, min, sec, total, best;
    std::cin >> n;
    for (int track = 1; track <= n; track++)
    {
        std::cin >> m;
        best = INT_MAX;
        total = 0;
        for (int i = 0; i < m; i++)
        {
            std::cin >> min >> sec;
            sec += 60 * min;
            best = std::min(best, sec);
            total += sec;
        }
        total /= m;
        std::cout << "Track " << track << ":\n"
                  << "Best Lap: " << best / 60 << " minute(s) " << best % 60 << " second(s).\n"
                  << "Average: " << total / 60 << " minute(s) " << total % 60 << " second(s).\n"
                  << '\n';
    }
}
