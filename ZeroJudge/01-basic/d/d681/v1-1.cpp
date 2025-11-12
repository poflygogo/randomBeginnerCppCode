#include <bitset>
#include <iostream>
#include <sstream>

int main()
{
    std::bitset<5> a, b;
    std::string line, op;
    std::istringstream iss;
    while (std::getline(std::cin, line))
    {
        iss.clear();
        iss.str(line);
        iss >> a;
        std::cout << a;
        while (iss >> op >> b)
        {
            if (op == "and")
            {
                std::cout << "&&" << b;
                a &= b;
            }
            else if (op == "or")
            {
                std::cout << "||" << b;
                a |= b;
            }
            else
            {
                std::cout << "\nshould not happen! op=\"" << op << "\"";
                return 0;
            }
        }
        std::cout << " = " << a << '\n';
    }
}
