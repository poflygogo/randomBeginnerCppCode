#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int idx = s.size() - 1;
  while (idx >= 0 && s[idx] == '0') {
    idx--;
  }
  if (idx < 0) {
    cout << 0;
  } else {
    while (idx >= 0) {
      cout << s[idx];
      idx--;
    }
    cout << endl;
  }
}