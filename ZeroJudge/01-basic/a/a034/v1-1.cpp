#include <iostream>
using namespace std;

int main() {
  int num, res[50];
  while (cin >> num) {
    int idx = 0;
    while (num) {
      res[idx] = num % 2;
      num /= 2;
      idx++;
    }
    idx--;
    while (idx >= 0) {
      cout << res[idx];
      idx--;
    }
    cout << endl;
  }
}