#include <iostream>
using namespace std;

// 不太嚴謹的笨方法
// 如果題目只給連接詞，而沒有其他單字的話，應輸出一個空字串(或什麼都不輸出)
// 這邊預設題目會給至少 1 個單字了

int main()
{
    string conj, word;
    cin >> conj;
    cin >> word;
    cout << word;
    while (cin >> word)
    {
        cout << ' ' << conj << ' ' << word;
    }
}
