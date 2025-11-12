#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct DataDetail {
    short num;
    short prime_sum;
    string sub_str;
    string origin_str;
};

void PrimeFactorSumHelper(short &result, short &num, const short &p) {
    if (num % p == 0) {
        result += p;
    }
    while (num % p == 0) {
        num /= p;
    }
}

short PrimeFactorSum(short num) {
    short result = 0;
    PrimeFactorSumHelper(result, num, 2);
    PrimeFactorSumHelper(result, num, 3);
    for (short i = 5; i * i <= num; i += 6) {
        PrimeFactorSumHelper(result, num, i);
        PrimeFactorSumHelper(result, num, i + 2);
    }
    if (num > 1) {
        result += num;
    }
    return result;
}

bool MyCompare(const DataDetail &a, const DataDetail &b) {
    if (a.prime_sum != b.prime_sum) {
        return a.prime_sum > b.prime_sum;
    } else if (a.sub_str != b.sub_str) {
        return a.sub_str < b.sub_str;
    } else {
        return a.num > b.num;
    }
}

DataDetail Analyze(const string &s) {
    short n = 0;
    string t = "";
    for (const char &c : s) {
        if (isdigit(c)) {
            n = n * 10 + (c - '0');
        } else {
            t += c;
        }
    }
    return DataDetail{n, PrimeFactorSum(n), t, s};
}

int main() {
    string s, t;
    short n;
    vector<DataDetail> arr;
    while (getline(cin, s)) {
        arr.push_back(Analyze(s));
    }
    sort(arr.begin(), arr.end(), MyCompare);
    for (const DataDetail &item : arr) {
        cout << item.origin_str << '\n';
    }
}
