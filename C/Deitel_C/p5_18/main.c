#include <stdio.h>

void even(int n);

int main(void)
{
    int y;
    int num=0;

    while(num < 5)
    {
    printf("Введите число ");
    scanf ("%d", &y);
    even(y);
    printf("\n");
    num++;
    }
    return 0;
}

void even(int x)
{
    if (x % 2 == 0)
        printf("1");
    else
        printf("0");
}
