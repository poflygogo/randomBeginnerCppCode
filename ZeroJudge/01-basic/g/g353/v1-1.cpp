#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    std::vector<int> arr;
    int n;
    while (iss >> n) {
        arr.push_back(n);
    }
    std::cout << arr[arr.size() / 2];
}
