#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void Print(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ',';
    }
    cout << arr[arr.size() - 1] << '\n';
}

void Solve(vector<int> &origin, vector<int> &even, vector<int> &even_index) {
    for (int i = 0; i < origin.size(); i++) {
        if (origin[i] % 2 == 0) {
            even.push_back(origin[i]);
            even_index.push_back(i);
        }
    }
    sort(even.begin(), even.end());
    for (int i = 0; i < even.size(); i++) {
        origin[even_index[i]] = even[i];
    }
}

int main() {
    vector<int> origin(20), even(20), even_index(20);

    stringstream stream;
    string line, token;
    while (getline(cin, line)) {
        origin.clear();
        stream.clear();
        stream.str(line);
        while (getline(stream, token, ',')) {
            origin.push_back(stoi(token));
        }

        even.clear();
        even_index.clear();
        Solve(origin, even, even_index);
        Print(origin);
    }
}
