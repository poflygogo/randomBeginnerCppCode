#include <algorithm>
#include <iostream>
#include <vector>

struct StudentInfo {
  public:
    int id;
    int s1, s2, s3;
    void initialize() {
        s1 *= 5;
        s2 *= 3;
        s3 *= 2;
        sum = s1 + s2 + s3;
        avg_int = sum / 10;
        avg_dec = sum % 10;
    };
    int get_sum() const { return sum; }
    std::pair<int, int> get_avg() const { return {avg_int, avg_dec}; }

  private:
    int sum;
    int avg_int, avg_dec;
};

bool CompStuInfo(const StudentInfo &a, const StudentInfo &b) {
    if (a.get_sum() != b.get_sum()) {
        return a.get_sum() > b.get_sum();
    } else if (a.s1 != b.s1) {
        return a.s1 > b.s1;
    } else if (a.s2 != b.s2) {
        return a.s2 > b.s2;
    } else if (a.s3 != b.s3) {
        return a.s3 > b.s3;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<StudentInfo> arr(n);
    for (StudentInfo &curr : arr) {
        std::cin >> curr.id >> curr.s1 >> curr.s2 >> curr.s3;
        curr.initialize();
    }
    std::sort(arr.begin(), arr.end(), CompStuInfo);
    for (const StudentInfo &stu : arr) {
        std::cout << stu.id << ' ';
        std::pair<int, int> avg = stu.get_avg();
        // 手動控制是否印出小數點的部分
        if (avg.second == 0) {
            std::cout << avg.first << '\n';
        } else {
            std::cout << avg.first << '.' << avg.second << '\n';
        }
    }
}
