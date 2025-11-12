#include <iostream>
using namespace std;

void Print(short arr[], const short &num) {
    for (short i = 0; i < num; i++) {
        cout << arr[i];
    }
    cout << '\n';
}

void Solve(short arr[], bool visited[], const short &num, short arr_size = 0) {
    if (arr_size == num) {
        Print(arr, num);
        return;
    }
    for (short i = num; i > 0; i--) {
        if (!visited[i]) {
            visited[i] = true;
            arr[arr_size] = i;
            Solve(arr, visited, num, arr_size + 1);
            visited[i] = false;
        }
    }
}

int main() {
    short num;
    while (cin >> num) {
        short arr[num];
        bool visited[num + 1] = {false};
        Solve(arr, visited, num);
    }
}
