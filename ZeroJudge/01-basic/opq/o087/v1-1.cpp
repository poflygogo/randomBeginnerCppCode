#include <algorithm>
#include <iostream>
#include <vector>

int Evaluat(std::string& Name) {
    int Score = 0;
    for (int i = 0; i < Name.size(); i++) {
        int CharCode = Name[i];
        Score += CharCode * 1123 % 1002;
        while (CharCode > 0) {
            Score += CharCode % 10;
            CharCode /= 10;
        }
    }
    return Score % 101;
}

struct Info {
    int id;
    int score;
    std::string name;
};

bool CompInfo(const Info& a, const Info& b) {
    if (a.score != b.score) {
        return a.score < b.score;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Info> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].name;
        arr[i].id = i;
        arr[i].score = Evaluat(arr[i].name);
    }
    std::sort(arr.begin(), arr.end(), CompInfo);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i].name << ' ' << arr[i].score << '\n';
    }
}
