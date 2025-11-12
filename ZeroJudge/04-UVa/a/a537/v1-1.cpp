#include <iostream>
#include <map>

bool IsPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += (i % 6 == 1 ? 4 : 2)) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::string PrimeFrequency(const std::string& s) {
    static std::map<char, int> counter;
    counter.clear();
    for (char c : s) {
        counter[c]++;
    }
    std::string res;
    res.reserve(counter.size());
    for (const std::pair<char, int> item : counter) {
        if (IsPrime(item.second)) {
            res += item.first;
        }
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    for (int test_case = 1; test_case <= t; test_case++) {
        std::string s;
        std::getline(std::cin, s);
        std::string res = PrimeFrequency(s);
        std::cout << "Case " << test_case << ": " << (res.empty() ? "empty" : res) << '\n';
    }
}
