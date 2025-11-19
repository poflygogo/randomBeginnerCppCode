#include <iostream>

using namespace std;

enum Result { deficient, perfect, abundant };

Result DPANumber(int n) {
    int sum = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return Result::perfect;
    } else if (sum < n) {
        return Result::deficient;
    } else {
        return Result::abundant;
    }
}

int main() {
    const string result[] = {"deficient", "perfect", "abundant"};
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << result[DPANumber(n)] << '\n';
    }
}
