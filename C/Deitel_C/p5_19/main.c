#include <stdio.h>

void side(int x);

int main(void)
{
    int p;
    printf("Введите параметр функции ");
    scanf("%d", &p);
    side(p);
    return 0;
}

void side(int y)
{
    int i,j;
    for (i=0; i<y; i++)
    {
       for(j=0; j<y; j++)
       {
           printf("*");
       }
           printf("\n");
    }
}
