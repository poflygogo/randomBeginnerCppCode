#include <algorithm>  // distance, find
#include <array>
#include <iostream>

using namespace std;

int main() {
    const array<string, 3> row = {"a", "e", "o"};
    const array<string, 7> col = {"a", "e", "i", "y", "o", "ou", "w"};
    const array<array<string, 7>, 3> value = {{
        {"a", "a", "ai", "a", "w", "w", "w"},
        {"y", "ei", "ei", "y", "ou", "ou", "w"},
        {"w", "ou", "oi", "w", "ou", "ou", "w"},
    }};

    string s;
    while (cin >> s && s != "END") {
        size_t i = s.find('-') - 1;
        string front = s.substr(i, 1);
        string back = (s.substr(i + 2, 2) == "ou" ? s.substr(i + 2, 2) : s.substr(i + 2, 1));   // 特判 "ou", 因為只有他是兩個字元寬

        size_t r = distance(row.begin(), find(row.begin(), row.end(), front));
        size_t c = distance(col.begin(), find(col.begin(), col.end(), back));

        s.replace(i, 2 + back.size(), value[r][c]);

        cout << s << '\n';
    }
}
