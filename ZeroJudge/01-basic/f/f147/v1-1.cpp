#include <stdio.h>

int main()
{
    int n, m;
    int total = 0;
    while (scanf("%d", &n) && n != 0)
    {
        scanf("%d", &m);
        switch (n)
        {
        case 1:
            switch (m)
            {
            case 1:
                printf("Medium Wac 4");
                total += 4;
                break;
            case 2:
                printf("WChicken Nugget 8");
                total += 8;
                break;
            case 3:
                printf("Geez Burger 7");
                total += 7;
                break;
            case 4:
                printf("ButtMilk Crispy Chicken 6");
                total += 6;
                break;
            case 5:
                printf("Plastic Toy 3");
                total += 3;
                break;
            default:
                printf("[Error] wtf is this? n=%d, m=%d", n, m);
                return 0;
            }
            break;
        case 2:
            switch (m)
            {
            case 1:
                printf("German Fries 2");
                total += 2;
                break;
            case 2:
                printf("Durian Slices 3");
                total += 3;
                break;
            case 3:
                printf("WcFurry 5");
                total += 5;
                break;
            case 4:
                printf("Chocolate Sunday 7");
                total += 7;
                break;

            default:
                printf("[Error] wtf is this? n=%d, m=%d", n, m);
                return 0;
            }
            break;

        default:
            printf("[Error] wtf is this? n=%d, m=%d", n, m);
            return 0;
        }
        printf("\n");
    }
    printf("Total: %d", total);
}
