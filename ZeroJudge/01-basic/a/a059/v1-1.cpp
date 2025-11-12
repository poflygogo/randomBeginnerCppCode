#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 建表，先把所有完全平方數列出來，這樣就不用每次都重新計算，只需要一一比較
 * @param limit 題目給的範圍
 * @return 完全平方數清單
 */
vector<int> square_number(int limit = 1000) {
    vector<int> *arr = new vector<int>;
    for (int i = 1, k = i * i; k <= limit; i++, k = i * i) {
        arr->push_back(k);
    }
    return *arr;
}

int main() {
    vector<int> arr = square_number();
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b;
        int sum = 0;
        cin >> a >> b;
        for (int ele : arr) {
            if (ele > b)
                break;
            else if (ele >= a)
                sum += ele;
        }
        cout << "Case " << i << ": " << sum << endl;
    }
}