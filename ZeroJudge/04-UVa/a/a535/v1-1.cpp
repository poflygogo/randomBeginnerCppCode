#include <algorithm>
#include <iostream>
#include <vector>

struct Quotation {
    int id;
    std::string name;
    double d;
    int r;
};

bool comp(const Quotation& a, const Quotation& b) {
    if (a.r != b.r) {
        return a.r > b.r;
    } else if (a.d != b.d) {
        return a.d < b.d;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int n, p;
    int test_case = 1;
    std::string s;
    s.reserve(80);
    while (std::cin >> n >> p && n && p) {
        std::cin.ignore();
        while (n--) {
            std::string i_dont_car;
            std::getline(std::cin, i_dont_car);
        }
        std::vector<Quotation> arr(p);
        for (int i = 0; i < p; i++) {
            arr[i].id = i;
            std::getline(std::cin, arr[i].name);
            std::cin >> arr[i].d >> arr[i].r;
            std::cin.ignore();
            for (int j = 0; j < arr[i].r; j++) {
                std::string i_dont_car;
                std::getline(std::cin, i_dont_car);
            }
        }

        auto res = std::min_element(arr.begin(), arr.end(), comp);
        std::cout << "RFP #" << test_case++ << '\n' << (*res).name << "\n\n";
    }
}
