// UVa 11000 - Bee
// ZeroJudge d261
// C++14

#include <iostream>
#include <vector>

int main() {
    std::vector<long long> male = {0, 1};
    std::vector<long long> female = {1, 1};

    int n;
    while (std::cin >> n && n >= 0) {
        while (male.size() <= n) {
            male.push_back(male.back() + female.back());
            female.push_back(*(male.end() - 2) + 1);
        }

        std::cout << male[n] << ' ' << male[n] + female[n] << '\n';
    }
}
