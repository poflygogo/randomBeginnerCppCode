#include <iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        int max_index = 0;
        int max_cnt = 1;
        int cnt = 1;
        for (int i = 1; i <= s.size(); ++i)
        {
            if (i < s.size() && s[i] == s[i - 1])
            {
                cnt += 1;
            }
            else if (cnt > max_cnt)
            {
                max_index = i - 1;
                max_cnt = cnt;
                cnt = 1;
            }
            else
            {
                cnt = 1;
            }
        }
        cout << s[max_index] << ' ' << max_cnt << '\n';
    }
}
