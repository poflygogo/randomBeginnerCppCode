#include <climits>
#include <stdio.h>

int main()
{
    int total_chain;
    int strongest_chain = 0;
    int length, curr_strong, num;

    scanf("%d", &total_chain);
    while (total_chain--)
    {
        scanf("%d", &length);
        curr_strong = INT_MAX;
        while (length--)
        {
            scanf("%d", &num);
            if (num < curr_strong)
            {
                curr_strong = num;
            }
        }
        if (curr_strong > strongest_chain)
        {
            strongest_chain = curr_strong;
        }
    }
    printf("%d", strongest_chain);
}
