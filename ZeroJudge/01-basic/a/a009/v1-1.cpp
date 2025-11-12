#include <iostream>
using namespace std;
#define DECRYPT 7   // 這題本質上就是凱薩密碼，把所有字符的 ascii 編碼 - 7 就是正解

int main()
{
    char a;
    while (cin >> a)
    {
        cout << char(int(a) - DECRYPT);
    }
    return 0;
}
