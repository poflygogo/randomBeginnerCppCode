#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 直接模擬
bool Solve(const int n, const vector<int>& arr) {
    auto it = arr.begin();
    stack<int> st;
    for (int num = 1; num <= n; num++) {
        st.push(num);
        while (!st.empty() && st.top() == *it) {
            it++;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        while (cin >> arr.front() && arr.front()) {
            for (size_t i = 1; i < n; i++) {
                cin >> arr[i];
            }
            cout << (Solve(n, arr) ? "Yes" : "No") << '\n';
        }
        cout << '\n';
    }
}
