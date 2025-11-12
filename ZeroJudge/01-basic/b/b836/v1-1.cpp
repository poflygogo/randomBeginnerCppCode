#include <iostream>
using namespace std;

// 雖然題目說所有數字都小於 2147483647
// 但其實這是騙人的(幹你娘)
// 輸入的數字包含超過 2147483647 的數字
// 如果真的用 int 就等著溢位吧

int main() {
    long long int n, m;
    while (cin >> n >> m) {
        long long int k = 1;
        while (m && n >= k) {
            n -= k;
            k += m;
        }
        cout << (n > 0 && m != 0 ? "No Stop!!\n" : "Go Kevin!!\n");
    }
}
