#include <algorithm>
#include <iostream>
#include <vector>

struct StudentInfo
{
  public:
    int id;
    std::string name;
    int a, b, c, d, e;
    void initialize()
    {
        s = a + b + c + d + e;
    }
    int sum() const
    {
        return s;
    }

  private:
    int s = 0;
};

bool comp(const StudentInfo &a, const StudentInfo &b)
{
    if (a.sum() != b.sum())
    {
        return a.sum() > b.sum();
    }
    else
    {
        return a.id < b.id;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<StudentInfo> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i].id >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
        arr[i].initialize();
    }

    std::sort(arr.begin(), arr.end(), comp);
    int prev_rank = 1;
    for (int i = 0; i < n; i++)
    {
        StudentInfo *stu = &arr[i];
        std::cout << stu->id << ' ' << stu->name << ' ' << stu->a << ' ' << stu->b << ' ' << stu->c << ' ' << stu->d << ' ' << stu->e << ' ' << stu->sum() << ' ';
        if (i == 0)
        {
            std::cout << 1 << '\n';
        }
        else if (stu->sum() == arr[i - 1].sum())
        {
            std::cout << prev_rank << '\n';
        }
        else
        {
            prev_rank = i + 1;
            std::cout << prev_rank << '\n';
        }
    }
}
