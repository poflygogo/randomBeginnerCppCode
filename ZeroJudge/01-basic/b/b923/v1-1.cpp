#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, command;
    stack<int> arr;
    cin >> n;
    while (n--) {
        cin >> command;
        switch (command) {
        case 1:
            arr.pop();
            break;
        case 2:
            cout << arr.top() << endl;
            break;
        case 3:
            cin >> command;
            arr.push(command);
            break;
        default:
            cout << "should not happen\n";
            return 0;
            break;
        }
    }
}
