#include <iostream>

int Scarecrow(const int n, const std::string& field) {
    int cnt = 0;
    int i = field.find('.');
    while (i != std::string::npos) {
        cnt++;
        i = field.find('.', i + 3);
    }
    return cnt;
}

int main() {
    int t;
    std::cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        std::string field;
        std::cin >> n >> field;
        std::cout << "Case " << test_case << ": " << Scarecrow(n, field) << '\n';
    }
}
