#include <stdio.h>

int time(int hour, int min, int  sek);

int main(void)
{
    int x,y,z, sum;

    printf("Введите количество часов: ");
    scanf("%d", &x);
    printf("Введите количество минут: ");
    scanf("%d", &y);
    printf("Введите количество секунд: ");
    scanf("%d", &z);

    sum = time(x,y,z);

    printf("Количество секунд равно %d\n", sum);

    return 0;
}

int time(int h, int m, int s)
{
    int result;

    result = (h*3600) + (m*60) + s;

    return result;
}
