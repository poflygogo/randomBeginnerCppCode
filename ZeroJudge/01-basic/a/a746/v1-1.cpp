#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void Print(const vector<string> &arr) {
    for (const string &s : arr) {
        cout << s << '\n';
    }
}

void Initialize(vector<string> &arr, const short &size) {
    const char kSpace = ' ';
    const char kRow = '-';
    const char kCol = '|';
    string s1 = string(size, kRow);
    string s2 = string(size, kSpace);
    s2.front() = kCol;
    s2.back() = kCol;
    arr.front() = s1;
    for (int i = 1; i < size - 1; i++) {
        arr[i] = s2;
    }
    arr.back() = s1;
}

void Link(vector<string> &arr, const short &x1, const short &y1, const short &x2, const short &y2) {
    const char &kToken = '*';
    short t1, t2;
    if (x1 == x2) {
        t1 = y1;
        t2 = y2;
        if (t1 > t2) {
            swap(t1, t2);
        }
        for (int c = t1; c <= t2; c++) {
            arr[x1][c] = kToken;
        }
    } else {
        t1 = x1;
        t2 = x2;
        if (t1 > t2) {
            swap(t1, t2);
        }
        for (int r = t1; r <= t2; r++) {
            arr[r][y1] = kToken;
        }
    }
}

void GildTheLily(const short &size, const short &m) {
    vector<string> arr(size + 2);
    Initialize(arr, size + 2);
    short x1, y1, x2, y2;
    cin >> x1 >> y1;
    for (short t = 1; t < m; t++) {
        cin >> x2 >> y2;
        Link(arr, x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }
    Print(arr);
}

int main() {
    short n, m;
    while (cin >> n >> m) {
        GildTheLily(n, m);
    }
}
