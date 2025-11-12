#include <algorithm>
#include <array>
#include <iostream>

int main() {
    const std::array<std::string, 7> data = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::string s;
    std::cin >> s;
    auto it = std::find(data.begin(), data.end(), s);
    if (it == data.end()) {
        std::cout << "error";
    } else {
        std::cout << it - data.begin();
    }
}
