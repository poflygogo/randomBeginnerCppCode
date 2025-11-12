#include <cmath>    // sqrt
#include <iomanip>  // fixed, setprecision
#include <iostream>
#include <vector>

using namespace std;

bool IsCoprime(int a, int b) {
    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a == 1;
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                cnt += IsCoprime(arr[i], arr[j]);
            }
        }

        if (cnt > 0) {
            double dn = n;
            double dcnt = cnt;
            cout << fixed << setprecision(6) << sqrt(dn * (dn - 1) / 2 * 6 / dcnt) << '\n';
        } else {
            cout << "No estimate for this data set.\n";
        }
    }
}
