#include <iostream>

int main()
{
    std::string a;
    std::cin >> a;
    int i = a.find_first_of("0123456789");
    int b = std::stoi(a.substr(i, a.size() - i));
    a.erase(i, a.size() - i);

    int a_to_int = 0;
    for (char c : a)
    {
        a_to_int *= 26;
        a_to_int += c - 'A' + 1;
    }
    std::cout << a_to_int * b;
}
