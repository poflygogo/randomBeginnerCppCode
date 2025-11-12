#include <algorithm>
#include <array>
#include <stdio.h>

int main()
{
    std::array<int, 3> lucky;
    std::array<int, 5> lottery, reward;

    scanf("%d %d %d", &lucky[0], &lucky[1], &lucky[2]);
    scanf("%d %d %d %d %d", &lottery[0], &lottery[1], &lottery[2], &lottery[3], &lottery[4]);
    scanf("%d %d %d %d %d", &reward[0], &reward[1], &reward[2], &reward[3], &reward[4]);

    int money = 0;
    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (lottery[i] == lucky[0] || lottery[i] == lucky[1])
        {
            money += reward[i];
        }
        if (lottery[i] == lucky[2])
        {
            money -= reward[i];
            flag = false;
        }
    }

    if (flag)
    {
        money *= 2;
    }

    printf("%d", std::max(0, money));
}
