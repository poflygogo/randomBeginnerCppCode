#include <algorithm>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << s << " can get " << std::count(s.begin(), s.end(), '8') * 10 << "% off.";
}
