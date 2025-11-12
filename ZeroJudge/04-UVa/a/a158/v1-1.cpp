#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    std::istringstream iss;
    while (n--) {
        std::getline(std::cin, s);
        iss.clear();
        iss.str(s);
        std::vector<int> arr;
        int a, b;
        while (iss >> a) {
            arr.push_back(a);
        }
        int res = 1;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                res = std::max(res, gcd(arr[i], arr[j]));
            }
        }

        std::cout << res << '\n';
    }
}
