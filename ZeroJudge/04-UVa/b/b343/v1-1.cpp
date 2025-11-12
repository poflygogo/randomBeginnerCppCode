#include <iostream>
#include <stack>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::vector<std::vector<int>> arr(a + 1);
        while (b--) {
            int x, y;
            std::cin >> x >> y;
            arr[x].push_back(y);
        }

        std::vector<char> visited(a + 1, false);
        std::stack<int> st;
        while (c--) {
            int x;
            std::cin >> x;
            st.push(x);
            while (!st.empty()) {
                int it = st.top();
                st.pop();
                if (!visited[it]) {
                    visited[it] = true;
                    for (int i = 0; i < arr[it].size(); i++) {
                        st.push(arr[it][i]);
                    }
                }
            }
        }

        int res = 0;
        for (int i = 1; i < visited.size(); i++) {
            res += visited[i];
        }
        std::cout << res << '\n';
    }
}
