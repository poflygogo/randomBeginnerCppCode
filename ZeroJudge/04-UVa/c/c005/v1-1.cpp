#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long f, area, animal, eco_level;
        long long sum = 0;
        cin >> f;
        while (f--) {
            cin >> area >> animal >> eco_level;
            sum += area * eco_level;
        }
        cout << sum << '\n';
    }
}
