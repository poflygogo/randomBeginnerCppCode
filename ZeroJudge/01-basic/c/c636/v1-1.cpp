#include <array>
#include <iostream>
using namespace std;

int main()
{
    //  注意:
    //  這邊不建議用 string 寫，像這樣
    //
    //      const string kTable = "豬鼠牛虎兔龍蛇馬羊猴雞狗豬"
    //  
    //  原因和文字編碼方式有關有關，如果堅持用字串的話......會很麻煩
    const int kPeriod = 12;
    const array<string, kPeriod> kTable = {"豬", "鼠", "牛", "虎", "兔", "龍",
                                           "蛇", "馬", "羊", "猴", "雞", "狗"};
    int n;
    while (cin >> n)
    {
        if (n > 0)
        {
            cout << kTable[n % kPeriod] << '\n';
        }
        else
        {
            cout << kTable[(n % kPeriod + kPeriod + 1) % kPeriod] << '\n';
        }
    }
}
