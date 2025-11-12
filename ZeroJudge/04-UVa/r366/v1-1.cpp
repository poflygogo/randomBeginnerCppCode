#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string s;
    set<string> words, tmp;
    while (getline(cin, s))
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0;
        while (i < s.size())
        {
            while (i < s.size() && !isalpha(s[i]))
            {
                ++i;
            }
            int j = i + 1;
            while (j < s.size() && isalpha(s[j]))
            {
                ++j;
            }
            words.insert(s.substr(i, j - i));
            i = j + 1;
        }
    }
    words.erase("");
    for (const string &ele : words)
    {
        cout << ele << '\n';
    }
}
