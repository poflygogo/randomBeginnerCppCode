#include <iostream>
using namespace std;

int main() {
  unsigned int m, d;
  string s;
  cin >> m >> d;
  switch ((m * 2 + d) % 3) {
    case 0:
      s = "普通";
      break;
    case 1:
      s = "吉";
      break;
    case 2:
      s = "大吉";
      break;
    default:
      break;
  }
  cout << s << endl;
  return 0;
}
