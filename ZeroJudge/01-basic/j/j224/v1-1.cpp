#include <iostream>
#include <set>

int main()
{
    int n, k;
    std::set<int> items;
    std::cin >> n;
    while (n--)
    {
        std::cin >> k;
        items.insert(k);
    }
    std::cout << items.size();
}
