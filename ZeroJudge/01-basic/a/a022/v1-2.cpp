#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string s) {
  int rgt = s.size() - 1;
  for (int lft = 0; lft < s.size() / 2; lft++, rgt--) {
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