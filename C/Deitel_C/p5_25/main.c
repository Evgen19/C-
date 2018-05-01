//Программа с помощью функции вычисляет минимальное из трех чисел
#include <stdio.h>

double Minimum(double x, double y, double z); //прототип функции

int main(void)
{
    double n1,n2,n3, res;
    printf("Введите три числа ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    res = Minimum(n1,n2, n3);
    printf("Минимальное число из трех чисел равно %0.2lf\n", res);

    return 0;
}

//Определение функции
double Minimum(double num1, double num2, double num3)
{
    double min;

    if (num1 < num2 && num1 < num3)

        min=num1;


    if (num2  < num1 && num2 < num3)

        min=num2;


    if (num3 < num1 && num3 < num2)

        min = num3;

    return min;


}
