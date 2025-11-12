#include <array>
#include <cmath>
#include <iostream>
#include <vector>

long long reduce(std::vector<long long>& arr, std::string op) {
    long long n = arr.front();
    for (int i = 1; i < arr.size(); i++) {
        if (op == "+") {
            n += arr[i];
        } else if (op == "-") {
            n -= arr[i];
        } else if (op == "*") {
            n *= arr[i];
        } else if (op == "/") {
            n /= arr[i];
        } else {
            n = (long long)powl(n, arr[i]);
        }
    }
    return n;
}

int main() {
    const std::array<std::string, 5> operators = {"+", "-", "*", "/", "**"};
    std::vector<long long> arr;
    long long n;
    while (std::cin >> n) {
        arr.push_back(n);
    }
    long long target = arr.back();
    arr.pop_back();
    for (int i = 0; i < operators.size(); i++) {
        if (reduce(arr, operators[i]) == target) {
            std::cout << operators[i] << '\n';
        }
    }
}
