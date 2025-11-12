#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    using namespace std;
    const vector<vector<pair<string, int>>> menu = {
        {{"Medium Wac", 4}, {"WChicken Nugget", 8}, {"Geez Burger", 7}, {"ButtMilk Crispy Chicken", 6}, {"Plastic Toy", 3}},
        {{"German Fries", 2}, {"Durian Slices", 3}, {"WcFurry", 5}, {"Chocolate Sunday", 7}}
    };

    int n, m;
    int total = 0;
    while (scanf("%d", &n) && n != 0)
    {
        scanf("%d", &m);
        n -= 1;
        m -= 1;
        cout << menu[n][m].first << ' ' << menu[n][m].second << '\n';
        total += menu[n][m].second;
    }
    cout << "Total: " << total;
}
