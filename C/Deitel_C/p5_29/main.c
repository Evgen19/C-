#include <stdio.h>

int gcd(int num1, int num2);

int main(void)
{
    int d,c, res;


    printf("Введите два числа ");
    scanf("%d %d", &d, &c);
    res=gcd(d,c);

    return 0;
}

int gcd(int x, int y)
{
    int i,j;

    int res1, res2, result;

    for (i=x; i>0; i--)
    {
        if (i%2 == 0)
        res1 = i;
    }

    for(j=y; j>0; j--)
        if(j%2 == 0)
            res2=j;

    if (res1 == res2)

        result = res1;
        printf("%d", res1);
}
