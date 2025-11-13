#include <array>
#include <climits>  // INT_MAX
#include <iostream>
#include <vector>

using namespace std;

void Solve(const int require, const int raid) {
    constexpr int kLimit = 8;
    static const array<pair<int, int>, 4> disk_list = {{{750, 250}, {500, 140}, {400, 110}, {250, 75}}};  // {size(GB), cost}

    pair<int, int> res_disk_type = {0, 0};
    int res_cost = INT_MAX;
    int res_total_disk = INT_MAX;
    for (size_t i = 0; i < disk_list.size(); i++) {
        const pair<int, int>& disk = disk_list[i];
        int total_disk = require / disk.first + (require % disk.first > 0);  // ceil
        if (raid == 1) {
            total_disk *= 2;
        } else if (raid == 5) {
            total_disk += 1;
        }

        if (total_disk > kLimit) {
            break;
        }

        int cost = disk.second * total_disk;

        if (cost < res_cost) {
            res_disk_type = disk;
            res_total_disk = total_disk;
            res_cost = cost;
        }
    }

    int disk_array = 0;
    if (raid == 0) {
        disk_array = res_disk_type.first * res_total_disk;
    } else if (raid == 1) {
        disk_array = res_disk_type.first * res_total_disk / 2;
    } else if (raid == 5) {
        disk_array = res_disk_type.first * (res_total_disk - 1);
    }

    cout << "Qty: " << res_total_disk << " Disk: " << res_disk_type.first << "GB"
         << " Price: $" << res_disk_type.second << '\n'
         << "Total price of this " << disk_array << "GB "
         << "array: $" << res_cost << "\n\n";
}

int main() {
    int require, raid;
    while (cin >> require >> raid) {
        Solve(require, raid);
    }
}
