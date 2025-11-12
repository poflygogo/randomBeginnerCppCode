#include <algorithm>
#include <iostream>
#include <vector>

struct StudentInfo
{
    std::string name;
    int classroom;
    int id;
    std::string intro;
};

bool Comp(const StudentInfo &a, const StudentInfo &b)
{
    if (a.classroom != b.classroom)
    {
        return a.classroom < b.classroom;
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<StudentInfo> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i].name >> arr[i].classroom >> arr[i].id >> arr[i].intro;
    }
    std::sort(arr.begin(), arr.end(), Comp);
    for (auto &&item : arr)
    {
        std::cout << item.classroom << ' ' << item.id << ' ' << item.name << '\n'
                  << item.intro << '\n';
    }
}
