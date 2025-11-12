#include <iostream>
#include <map>
#include <sstream>

int main() {
    int n;
    std::string s;
    std::map<std::string, int> counter;
    std::istringstream iss;
    std::cin >> n;
    std::cin.ignore(75, '\n');
    while (n--) {
        std::getline(std::cin, s);
        iss.clear();
        iss.str(s);
        iss >> s;
        counter[s]++;
    }
    for (auto&& item : counter) {
        std::cout << item.first << ' ' << item.second << '\n';
    }
}
