// UVa 10929 - You can say 11
// ZeroJudge d235
// C++14

#include <iostream>
#include <string>

bool isDivideBy11(std::string &num) {
    int sum = 0;
    for (size_t i = 0; i < num.size(); ++i) {
        if (i % 2 == 0) {
            sum += num[i] - '0';
        } else {
            sum -= num[i] - '0';
        }
    }
    return sum % 11 == 0;
}

int main() {
    std::string big_int;
    while (std::getline(std::cin, big_int) && big_int != "0") {
        std::cout << big_int << " is" << (isDivideBy11(big_int) ? "" : " not")
                  << " a multiple of 11.\n";
    }
}
