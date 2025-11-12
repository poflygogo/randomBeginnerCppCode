#include <iostream>
#include <string>
using namespace std;
#define DECRYPT 7   // 這題本質上就是凱薩密碼，把所有字符的 ascii 編碼 - 7 就是正解

int main()
{
    string a;
    while (getline(cin, a))
    {
        for (char& c: a)
        {
            cout << char(int(c) - DECRYPT);
        }
    }
    return 0;
}
