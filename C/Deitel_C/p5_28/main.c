//Программа изменяет порядок вводимого числа, т.е число пишется  в обратном порядке
#include <stdio.h>

void revers(int num);

int main(void)
{
    int number;
    printf("Введите число ");
    scanf("%d", &number);
    revers(number);
    return 0;
}

void revers(int num)
{
    int res, res1, res2, res3, res4, res5;
    res = num / 1000;
    res1 = num % 1000;
    res2 = res1 / 100;
    res3 = res1 % 100;
    res4 = res3 / 10;
    res5 = res3 % 10;
    printf("%d %d %d %d\n", res5, res4, res2, res);
}
