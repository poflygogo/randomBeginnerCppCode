#include <iomanip>  // fixed, setprecision
#include <iostream>

using namespace std;

int main() {
    double fo, fe, fa;
    while (cin >> fo >> fe >> fa && (fo || fe || fa)) {
        cout << fixed << setprecision(2) << fo / fe << ' ' << fa / fo * fe << '\n';
    }
}
