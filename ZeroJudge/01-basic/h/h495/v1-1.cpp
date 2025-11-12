#include <array>
#include <iostream>

int main() {
    int t, a, b, c, d, e, f, g;
    const std::array<int, 6> kTable = {-1, 1, 1, 2, 3, 1};
    std::array<int, 6> data;
    std::cin >> t;
    while (t--) {
        int score = 0;
        std::cin >> a >> b >> c >> d >> e >> f >> g;
        for (int i = 0; i < 6; i++) {
            std::cin >> data[i];
        }

        if (a <= 1)     score -= 1;
        else if (a > 5) score += 4;
        else            score += a - 1;

        if (b == 0)      score -= 1;
        else if (b >= 4) score += 4; 
        else             score += b;

        if (c == 0)      score -= 1;
        else if (c <= 3) score += 1;
        else if (c <= 5) score += 2;
        else if (c <= 7) score += 3;
        else             score += 4;

        if (d == 0)      score -= 1;
        else if (d >= 4) score += 4;
        else             score += d;

        if (e == 0)      score -= 1;
        else if (e <= 3) score += 1;
        else if (e <= 5) score += 2;
        else if (e <= 7) score += 3;
        else             score += 4;
        
        if (f == 0)      score -= 1;
        else if (f <= 2) score += 1;
        else if (f <= 4) score += 2;
        else if (f <= 6) score += 3;
        else             score += 4;
        
        if (g == 0)      score -= 1;
        else if (g == 1) score += 1;
        else if (g <= 3) score += 2;
        else if (g <= 5) score += 3;
        else             score += 4;

        for (int i = 0; i < 6; i++) {
            score += kTable[i] * data[i];
        }
        
        std::cout << score << '\n';
    }
}
