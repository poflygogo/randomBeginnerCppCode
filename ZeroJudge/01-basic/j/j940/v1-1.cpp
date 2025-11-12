#include <iostream>

int main()
{
    std::string s;
    int n;
    std::cin >> s >> n;
    std::cout << s.substr(0, n + 1) << '.' << s.substr(n + 1, s.size() - n);
}
