#include <iostream>
using namespace std;

int main() {
    int n, result;
    while (cin >> n && n) {
        result = 0;
        for (int rgt = n / 2 + 1; rgt > 1; rgt--) {
            for (int lft = rgt - 1; lft > 0; lft--) {
                int sum = (lft + rgt) * (rgt - lft + 1) / 2;
                if (sum > n) {
                    break;
                } else if (sum == n) {
                    result += 1;
                    break;
                }
            }
        }
        cout << result << '\n';
    }
}

// Time Complexity: O(N^2)
