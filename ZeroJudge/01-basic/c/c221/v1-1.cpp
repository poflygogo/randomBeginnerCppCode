#include <limits>
#include <iostream>
using namespace std;

int main()
{
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::max();
    cout << a << ' ' << b;
}

// 目標是傳入兩個 <= 1e10 的正整數，且兩數相加會溢位的兩個數字。
