#include <iostream>
using namespace std;

void Solve(char arr[], bool visited[], const short &num, short arr_size = 0) {
    if (arr_size == num) {
        cout << arr;
        return;
    }
    for (short i = num; i > 0; i--) {
        if (!visited[i]) {
            visited[i] = true;
            arr[arr_size] = '0' + i;
            Solve(arr, visited, num, arr_size + 1);
            visited[i] = false;
        }
    }
}

int main() {
    short num;
    while (cin >> num) {
        char arr[num + 2];
        arr[num] = '\n';
        arr[num + 1] = '\0'; 
        bool visited[num + 1] = {false};
        Solve(arr, visited, num);
    }
}
