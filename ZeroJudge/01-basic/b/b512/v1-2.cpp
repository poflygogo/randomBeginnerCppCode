#include <iostream>
#include <unordered_map>
using namespace std;

// Each case has several key-value pair and ends with case 0:0.
// sample input:
//      "1:5 1000:55 1000000:555 0:0"
//      "10:6 10000:66 100000:666 1000000:2 0:0"
unordered_map<int, int> StreamToMap() {
    unordered_map<int, int> result;
    int key, val;
    char _colon;
    while (cin >> key >> _colon >> val) {
        printf("key=%d, val=%d\n", key, val);
        if (key == 0 && val == 0) {
            break;
        }

        result[key] = val;
    }
    cout << "aaaaaaaa\n";
    return result;
}

int MapGet(const unordered_map<int, int> &container, const int &key) {
    auto result = container.find(key);
    return result != container.end() ? result->second : 0;
}

int main() {
    unordered_map<int, int> vector1 = StreamToMap();
    unordered_map<int, int> vector2 = StreamToMap();

    int product = 0;
    for (const pair<int, int> &item : vector1) {
        product += item.second * MapGet(vector2, item.first);
    }
    cout << product << '\n';
}
