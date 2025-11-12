#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, command;
    int tmp;
    stack<int> arr;
    cin >> n;
    while (n--) {
        cin >> command;
        switch (command) {
        case 1:
            cin >> tmp;
            arr.push(tmp);
            break;
        case 2:
            cout << (arr.empty() ? -1 : arr.top()) << endl;
            break;
        case 3:
            if (!arr.empty()) {
                arr.pop();
            }
            break;
        default:
            cout << "should not happen\n";
            return 0;
            break;
        }
    }
}
