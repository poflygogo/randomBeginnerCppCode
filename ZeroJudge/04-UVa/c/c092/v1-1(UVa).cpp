#include <cmath>    // sqrt
#include <iomanip>  // fixed, setpercious
#include <iostream>

using namespace std;

int main() {
    const string directions = "NESW";
    const string sep = ",.";
    const double sqrt_2 = sqrt(2);
    int test_case = 1;
    string s;
    while (getline(cin, s) && s != "END") {
        size_t i = 0;
        double x = 0;
        double y = 0;
        while (i < s.size() && s[i] != '.') {
            size_t j = s.find_first_of(directions, i);
            size_t k = s.find_first_of(sep, j);
            int step = stoi(s.substr(i, j - i));
            string dir = s.substr(j, k - j);

            if (dir == "N") {
                y += step;
            } else if (dir == "S") {
                y -= step;
            } else if (dir == "E") {
                x += step;
            } else if (dir == "W") {
                x -= step;
            } else if (dir == "NE") {
                x += step / sqrt_2;
                y += step / sqrt_2;
            } else if (dir == "NW") {
                x -= step / sqrt_2;
                y += step / sqrt_2;
            } else if (dir == "SE") {
                x += step / sqrt_2;
                y -= step / sqrt_2;
            } else if (dir == "SW") {
                x -= step / sqrt_2;
                y -= step / sqrt_2;
            }

            i = k + 1;
        }
        cout << "Map #" << test_case++ << '\n'
             << "The treasure is located at (" << fixed << setprecision(3) << x << ',' << y
             << ").\n"
             << "The distance to the treasure is " << sqrt(pow(x, 2) + pow(y, 2)) << ".\n\n";
    }
}
