#include <cctype>   // islower()
#include <iostream>
#include <string>

bool is_prime(int n) {
    if (n <= 3) return true; // idk why 1 counts as a prime number
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::string s;
    while (std::cin >> s) {
        int sum = 0;
        for (char c : s) {
            sum += islower(c) ? c - 'a' + 1 : c - 'A' + 27;
        }
        std::cout << "It is " << (is_prime(sum) ? "" : "not ") << "a prime word.\n";
    }
}
