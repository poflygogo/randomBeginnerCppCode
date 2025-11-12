#include <iostream>
#include <map>

int main() {
    int n;
    std::string s;
    std::map<std::string, int> counter;
    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        std::cin >> s;
        counter[s]++;
        std::cin >> s >> s;
    }
    for (auto&& item : counter) {
        std::cout << item.first << ' ' << item.second << '\n';
    }
}
