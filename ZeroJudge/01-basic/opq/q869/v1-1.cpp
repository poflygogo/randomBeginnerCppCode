#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

bool Comp(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> arr(n);
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, arr[i]);
    }
    std::sort(arr.begin(), arr.end(), Comp);

    int max_size = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].size() > max_size) {
            max_size = arr[i].size();
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << std::setw(max_size) << std::right << arr[i] << '\n';
    }
}
