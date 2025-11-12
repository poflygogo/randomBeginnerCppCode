#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) {
  int a = 100;
  for (int lft = 0; lft < s.size() / 2; lft++) {
    int rgt = s.size() - lft - 1;
    if (s[lft] != s[rgt])
      return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  if (is_palindrome(s))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}