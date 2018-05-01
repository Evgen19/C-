#include <stdio.h>

int gualityPoints(int num);

int main(void)
{
    int value, result;

    printf("Введите количество балов, полученных студентом ");
    scanf("%d", &value);

    result= gualityPoints(value);
    printf("Оценка студента: %d\n",result);
    return 0;
}

int gualityPoints(int x)
{
    int grade;
    if (x < 60)
        grade = 0;
    if(x >= 60 && x <= 69)
        grade = 1;
    if(x > 69 && x <= 79)
        grade = 2;
    if(x > 79 && x <= 89)
        grade = 3;
    if(x > 89 && x <= 100)
        grade = 4;

    return grade;
}
