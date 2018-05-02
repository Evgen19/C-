/*Инициализирует элементы массива s
четными целыми числами от 2 до 20*/
#include <stdio.h>

#define SIZE 10

int main(int argc, char *argv[])
{
    int s[SIZE], j;

    for(j=0; j <= SIZE-1; j++) /*устанавливает значения*/
        s[j]=2+2*j;

    printf("%s%13s\n", "Element", "Value");

    for(j=0; j<=SIZE-1; j++)/*выводит значения*/
        printf("%7d%13d\n", j, s[j]);

    return 0;
}
