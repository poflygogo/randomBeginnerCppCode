#include <algorithm>  // find
#include <array>
#include <iomanip>  // fixed, setprecision
#include <iostream>
#include <list>
#include <sstream>  // istream

using namespace std;

template <size_t N>
istream& operator>>(istream& iss, array<int, N>& arr) {
    for (size_t i = 0; i < N; i++) {
        iss >> arr[i];
    }
    return iss;
}

int main() {
    constexpr int kCacheLimit = 16;
    constexpr int kTotalNumber = 20;
    array<int, kTotalNumber> page_ids = {};
    list<int> cache;
    double cases_counter = 0;
    double cache_hit_counter = 0;
    while (cin >> page_ids) {
        cases_counter += kTotalNumber;
        for (size_t i = 0; i < kTotalNumber; i++) {
            auto it = find(cache.begin(), cache.end(), page_ids[i]);
            if (it == cache.end()) {
                cache.push_back(page_ids[i]);
                if (cache.size() > 16) {
                    cache.pop_front();
                }
            } else {
                cache_hit_counter++;
                cache.erase(it);
                cache.push_back(page_ids[i]);
            }
        }
        cout << "cache hit rate: " << fixed << setprecision(2)
             << 100 * cache_hit_counter / cases_counter << "%\n";
    }
}
