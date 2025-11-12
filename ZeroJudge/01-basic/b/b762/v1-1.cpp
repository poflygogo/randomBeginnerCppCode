#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std;

void GetKill(int &k, int &d, int &a, int &cnt) {
    k += 1;
    cnt += 1;
    switch (cnt) {
    case 1:
    case 2:
        cout << "You have slain an enemie.\n";
        break;
    case 3:
        cout << "KILLING SPREE!\n";
        break;
    case 4:
        cout << "RAMPAGE~\n";
        break;
    case 5:
        cout << "UNSTOPPABLE!\n";
        break;
    case 6:
        cout << "DOMINATING!\n";
        break;
    case 7:
        cout << "GUALIKE!\n";
        break;
    default:
        cout << "LEGENDARY!\n";
        break;
    }
}

void GetAssist(int &k, int &d, int &a, int &cnt) { a += 1; }

void Die(int &k, int &d, int &a, int &cnt) {
    d += 1;
    cout << (cnt < 3 ? "You have been slained.\n" : "SHUTDOWN.\n");
    cnt = 0;
}

int main() {
    int n;
    string s;
    cin >> n;
    int k = 0;
    int d = 0;
    int a = 0;
    int cnt = 0;
    map<string, function<void(int&, int&, int&, int&)>> comm = {
        {"Get_Kill" , GetKill},
        {"Get_Assist", GetAssist},
        {"Die", Die}
    };
    while (n--) {
        cin >> s;
        comm[s](k, d, a, cnt);
    }
    cout << k << '/' << d << '/' << a << endl;
}
