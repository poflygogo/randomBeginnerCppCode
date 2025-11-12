#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct JobInfo {
    int id;
    int time;
    int punish;
};

bool Comp(const JobInfo& a, const JobInfo& b) {
    if (a.time * b.punish == b.time * a.punish) {
        return a.id < b.id;
    } else {
        return a.time * b.punish < b.time * a.punish;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<JobInfo> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].id = i + 1;
            cin >> arr[i].time >> arr[i].punish;
        }
        sort(arr.begin(), arr.end(), Comp);
        for (int i = 0; i < n; i++) {
            std::cout << arr[i].id << (i + 1 != n ? ' ' : '\n');
        }
        cout << '\n';
    }
}
