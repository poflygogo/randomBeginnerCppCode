#include <iostream>
using namespace std;

pair<bool, int> Snail(double target, double up, double down, double fatigue) {
    double place = 0.0;
    int day = 1;
    fatigue = up * fatigue / 100;
    while (true) {
        place += up;
        if (place > target) {
            return {true, day};
        }
        place -= down;
        if (place < 0) {
            return {false, day};
        }
        up = max(0.0, up - fatigue);
        day++;
    }
}

int main() {
    double target, up, down, fatigue;
    while (cin >> target >> up >> down >> fatigue && (target || up || down || fatigue)) {
        pair<bool, int> res = Snail(target, up, down, fatigue);
        cout << (res.first ? "success" : "failure") << " on day " << res.second << '\n';
    }
}
