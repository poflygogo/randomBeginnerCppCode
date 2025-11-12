#include <stdio.h>

// 題目說最多不超過 100 個數字，所以開 100
int nums[100];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &nums[i]);
        }

        int lft = 0;
        int rgt = n;
        bool reverse = false;
        while (lft < rgt)
        {
            if (reverse)
            {
                for (int i = rgt - 1; i >= lft; i--)
                {
                    printf("%d ", nums[i]);
                }
                rgt--;
            }
            else
            {
                for (int i = lft; i < rgt; i++)
                {
                    printf("%d ", nums[i]);
                }
                lft++;
            }
            printf("\n");
            reverse ^= 1;
        }
        printf("\n");
    }
}
