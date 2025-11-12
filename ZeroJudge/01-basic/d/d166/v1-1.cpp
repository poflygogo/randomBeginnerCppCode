#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> Solve(const vector<int> &arr)
{
    vector<int> res(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < res.size(); j++)
        {
            if (res[j] == 0 && cnt == arr[i])
            {
                res[j] = i + 1;
                break;
            }
            else if (res[j] == 0 || res[j] > i)
            {
                cnt += 1;
            }
        }
    }
    return res;
}

int main()
{
    string line;
    vector<int> arr;
    arr.reserve(50);
    istringstream iss;
    int tmp;
    while (getline(cin, line) && line != "-1")
    {
        iss.str(line);
        while (iss >> tmp)
        {
            arr.push_back(tmp);
        }

        vector<int> res = Solve(arr);
        for (auto &&i : res)
        {
            cout << i << ' ';
        }
        cout << '\n';
        iss.clear();
        arr.clear();
    }
}
