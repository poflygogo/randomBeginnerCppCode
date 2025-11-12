#include <iostream>
using namespace std;

int main()
{
    unsigned int year;
    while (cin >> year)
    {
        // 三元表達式
        string result = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) ? "閏年" : "平年";
        cout << result << endl;
    }
    return 0;
}
