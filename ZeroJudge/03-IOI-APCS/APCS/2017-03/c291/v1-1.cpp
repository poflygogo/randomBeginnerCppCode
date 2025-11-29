// Zerojudge c291
// APCS 2017-03 2 小群體
// c++14

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // read friends info
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<char> visited(n, false);
    int cnt = 0;
    for (int num = 0; num < n; ++num) {
        if (visited[num]) {
            continue;
        }
        cnt++;
        int k = num;
        // dfs(while loop version)
        while (visited[k] == false) {
            visited[k] = true;
            k = arr[k];
        }
    }
    std::cout << cnt << '\n';
}
