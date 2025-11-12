#include <iostream>
using namespace std;

int main() {
    int n, a, b, yee;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        yee = 100 - a - b;
        if (0 < yee && yee <= 30) {
            cout << "sad!\n";
        } else if (30 <= yee && yee <= 60) {
            cout << "hmm~~\n";
        } else if (60 < yee && yee < 100) {
            cout << "Happyyummy\n";
        } else {
            cout << "evil!!\n";
        }
    }
}
