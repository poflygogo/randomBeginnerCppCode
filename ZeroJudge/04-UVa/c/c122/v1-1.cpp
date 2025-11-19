#include <iostream>
#include <vector>

using namespace std;

string get_num_id(int n) {
    static const string ids[] = {"th", "st", "nd", "rd"};
    int mod = n % 10;
    if (n % 100 >= 11 && n % 100 <= 13) return ids[0];
    if (mod == 1) return ids[1];
    if (mod == 2) return ids[2];
    if (mod == 3) return ids[3];
    return ids[0];
}

int main() {
    int n;
    vector<int> humble_numbers;
    int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
    humble_numbers.push_back(1);
    while (cin >> n && n) {
        while (humble_numbers.size() < n) {
            int next_humble_p2 = humble_numbers[p2] * 2;
            int next_humble_p3 = humble_numbers[p3] * 3;
            int next_humble_p5 = humble_numbers[p5] * 5;
            int next_humble_p7 = humble_numbers[p7] * 7;
            int next_humble_number = min(next_humble_p2, min(next_humble_p3, min(next_humble_p5, next_humble_p7)));
            humble_numbers.push_back(next_humble_number);
            if (next_humble_number == next_humble_p2) p2++;
            if (next_humble_number == next_humble_p3) p3++;
            if (next_humble_number == next_humble_p5) p5++;
            if (next_humble_number == next_humble_p7) p7++;
        }
        cout << "The " << n << get_num_id(n) << " humble number is " << humble_numbers[n - 1] << "." << '\n';
    }
}
