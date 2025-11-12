#include <iostream>
#include <numeric>
#include <vector>

int Find(std::vector<int>& arr, int x) {
    if (arr[x] == x) {
        return x;
    }
    arr[x] = Find(arr, arr[x]);
    return arr[x];
}

void Union(std::vector<int>& arr, std::vector<int>& size, int x, int y) {
    int x_root = Find(arr, x);
    int y_root = Find(arr, y);
    if (x_root != y_root) {
        if (size[x_root] < size[y_root]) {
            std::swap(x_root, y_root);
        }
        arr[y_root] = x_root;
        size[x_root] += size[y_root];
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr(n + 1);
    std::iota(arr.begin(), arr.end(), 0);
    std::vector<int> size(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        Union(arr, size, a, b);
    }

    std::vector<bool> visited(n + 1, false);
    std::vector<int> result;
    result.reserve(n + 1);
    for (int i = 1; i <= n; i++) {
        int root = Find(arr, i);
        if (!visited[root]) {
            visited[root] = true;
            result.push_back(i);
        }
    }

    std::cout << '[';
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << (i == result.size() - 1 ? "]" : ", ");
    }
}
