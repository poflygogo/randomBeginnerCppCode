#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n) {
        // Kadane's algorithm
        int max_global = 0;
        int curr = 0;
        while (n--) {
            int k;
            std::cin >> k;
            curr += k;
            if (curr < 0) {
                curr = 0;
            }
            max_global = std::max(max_global, curr);
        }

        if (max_global > 0) {
            std::cout << "The maximum winning streak is " << max_global << ".\n";
        } else {
            std::cout << "Losing streak.\n";
        }
    }
}
