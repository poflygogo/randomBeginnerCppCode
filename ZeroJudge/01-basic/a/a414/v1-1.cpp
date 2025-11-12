#include <iostream>
using namespace std;

int main() {
    int num;
    while (scanf("%d", &num) && num) {
        int cnt = 0;
        while (num && num % 2 == 1) {
            num /= 2;
            cnt++;
        }
        printf("%d\n", cnt);
    }
}