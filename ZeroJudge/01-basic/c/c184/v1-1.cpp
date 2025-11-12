#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Sum(vector<int> &arr)
{
    int res = 0;
    for (const int &num : arr)
    {
        res += num;
    }
    return res;
}

vector<int> Factorize(int num)
{
    vector<int> res = {1};
    for (int p = 2; p * p <= num; ++p)
    {
        if (num % p == 0)
        {
            res.push_back(p);
            int tmp = num / p;
            if (res.back() != tmp)
            {
                res.push_back(tmp);
            }
        }
    }
    sort(res.begin(), res.end());
    if (res.back() == num)
    {
        res.pop_back();
    }
    res.push_back(Sum(res));
    return res;
}

void PrintFactorize(vector<int> &arr)
{
    string res;
    int len = arr.size();
    for (int i = 0; i < len - 1; ++i)
    {
        cout << arr[i];
        if (i < len - 2)
        {
            cout << '+';
        }
    }
    cout << '=' << arr[len - 1] << '\n';
}

int main()
{
    int num;
    cin >> num;
    vector<int> num_factors = Factorize(num);
    PrintFactorize(num_factors);
    if (num_factors.back() == num)
    {
        cout << num << " is perfect.\n";
    }
    else
    {
        vector<int> num2_factors = Factorize(num_factors.back());
        PrintFactorize(num2_factors);
        if (num2_factors.back() == num)
        {
            cout << num << " and " << num_factors.back() << " are friends.\n";
        }
        else
        {
            cout << num << " has no friends.\n";
        }
    }
}
