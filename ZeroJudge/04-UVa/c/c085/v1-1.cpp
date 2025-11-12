#include <array>
#include <iostream>

using namespace std;

int main() {
    int t = 1;
    array<int, 10000> flag;
    int z, i, m, l;
    while (cin >> z >> i >> m >> l && z && i && m && l) {
        flag.fill(0);
        int cnt = 0;
        while (!flag[l]) {
            flag[l] = cnt++;
            l = (z * l + i) % m;
        }
        cout << "Case " << t++ << ": " << cnt - flag[l] << '\n';
    }
}
