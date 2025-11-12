#include <iostream>
using namespace std;

int main() {
    // n < size of array(n x n)
    // m < numbers of request
    // x1, y1 < the top left position
    // x2, y2 < the button right position
    int n, m, x1, y1, x2, y2;
    while (cin >> n >> m) {
        // initialize
        int arr[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            arr[0][i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            arr[i][0] = 0;
        }

        // read the data and do prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }

        // check the result
        while (m--) {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << '\n';
        }
    }
}
