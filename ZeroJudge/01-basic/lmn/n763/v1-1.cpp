#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n;
    std::queue<int> q;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        q.push(tmp);
    }

    while (q.size() > 1) {
        int num = q.front();
        q.pop();
        if (num % 2 == 0) {
            q.pop();
        }
        q.push(num);
    }

    std::cout << q.front();
}
