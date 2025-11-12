#include <iostream>
using namespace std;

int main() {
    int res[3] = {0};
    int total_line, n;
    cin >> total_line;
    while (total_line--) {
        cin >> n;
        res[n % 3]++;
    }
    for (int val : res) {
        cout << val << " ";
    }
}