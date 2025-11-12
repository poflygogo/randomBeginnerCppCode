#include <algorithm>  // next_permutation
#include <array>
#include <iostream>

using namespace std;

int main() {
    array<string, 6> bins = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};
    array<int, 9> buckets;
    while (cin >> buckets[0]) {
        int total = buckets[0];
        for (int i = 1; i < buckets.size(); i++) {
            cin >> buckets[i];
            total += buckets[i];
        }

        array<int, 6> cost;
        cost.fill(total);
        array<int, 3> perm = {0, 1, 2};
        int idx = 0;
        do {
            for (int i = 0; i < 3; i++) {
                cost[idx] -= buckets[i * 3 + perm[i]];
            }
            idx++;
        } while (next_permutation(perm.begin(), perm.end()));

        int res_idx = 0;
        for (int i = 0; i < 6; i++) {
            if (cost[i] < cost[res_idx] || (cost[i] == cost[res_idx] && bins[i] < bins[res_idx])) {
                res_idx = i;
            }
        }

        std::cout << bins[res_idx] << ' ' << cost[res_idx] << '\n';
    }
}
