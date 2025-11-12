#include <algorithm>  // for_each
#include <iostream>
#include <map>
#include <vector>

int Gcd(int a, int b) { return !b ? a : Gcd(b, a % b); }

void Solve(int a, int b) {
    std::map<int, int> reminder;
    std::vector<int> decimal;
    int idx = 0;
    while (a && reminder.find(a) == reminder.end()) {
        reminder[a] = idx++;
        decimal.push_back(a * 10 / b);
        a = a * 10 % b;
    }

    std::string s = ".";
    std::for_each(decimal.begin(), decimal.end(), [&](const int n) { s += std::to_string(n); });
    for (int i = 0; i < s.size(); i += 50) {
        std::cout << s.substr(i, 50) << '\n';
    }

    if (a != 0) {
        std::cout << "The last " << decimal.size() - reminder[a] << " digits repeat forever.\n";
    } else {
        std::cout << "This expansion terminates.\n";
    }
}

int main() {
    int a, b;
    bool is_first_case = true;
    while (std::cin >> a >> b && a && b) {
        if (!is_first_case) {
            std::cout << '\n';
        }
        is_first_case = false;
        int g = Gcd(a, b);
        a /= g;
        b /= g;
        Solve(a, b);
    }
}
