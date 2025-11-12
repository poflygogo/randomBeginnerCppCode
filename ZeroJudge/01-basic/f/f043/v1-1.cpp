#include <stdio.h>
#include <utility>

int main()
{
    int result, num1;
    scanf("%d %d", &result, &num1);
    if (result == num1)
    {
        num1 -= 3;
    }

    int num2 = result - num1;
    if (num1 > num2)
    {
        std::swap(num1, num2);
    }
    printf("%d+%d=%d", num1, num2, result);
}
