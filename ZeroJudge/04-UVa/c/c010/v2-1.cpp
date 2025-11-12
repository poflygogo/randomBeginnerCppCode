#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int> lft;
    priority_queue<int, vector<int>, greater<int>> rgt;
    int n;
    while (cin >> n) {
        lft.push(n);
        if (!lft.empty() && !rgt.empty() && lft.top() > rgt.top()) {
            rgt.push(lft.top());
            lft.pop();
        }

        // balance the size of two heap
        if (lft.size() > rgt.size() + 1) {
            rgt.push(lft.top());
            lft.pop();
        } else if (rgt.size() > lft.size()) {
            lft.push(rgt.top());
            rgt.pop();
        }

        if (lft.size() > rgt.size()) {
            cout << lft.top() << '\n';
        } else {
            cout << (lft.top() + rgt.top()) / 2 << '\n';
        }
    }
}
