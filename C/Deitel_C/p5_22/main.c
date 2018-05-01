#include <stdio.h>

void result(int x);

int main(void)
{
    int x;
    printf("Введите число ");
    scanf("%d", &x);
    result(x);

    return 0;
}

void result (int x)
{
   int res, res1, res2, res3, res4, res5;

   res = x/1000;
   res1=x%1000;
   res2=res1/100;
   res3=res1%100;
   res4=res3/10;
   res5=res3%10;

   printf("%d %d %d %d\n", res, res2, res4, res5);
}
