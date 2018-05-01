#include <stdio.h>

//Возвращает эквивалент по шкале Цельсия температуры, заданной по шкале Фаренгейта
double celsius(double tem);
//Возвращает эквивалент по шкале Фаренгейта температуры, заданной по шкале Цельсия
double fahrenheit(double temp);

int main(void)
{
    double j,i,g,k;


    printf("Температура по Фаренгейту\t Температура по Цельсию\n");

    //Печатаем таблицу температуры по Фаренгейту и ее эквивалент по Цельсию

    for (i = 0, j=0; i<=100, j<=100; i++, j++)
    {
        printf("%0.2lf \t\t\t\t %0.2lf\n", i, celsius(j));
    }

    printf("\n");

    printf("Температура по Цельсию\t Температура по Фаренгейту\n");

    //Печатаем таблицу температуры по Цельсию и ее эквивалент по Фаренгейту

    for (g = 32, k=32; g<=212, k<=212; g++, k++)
    {
        printf("%0.2lf \t\t\t\t %0.2lf\n", g,  fahrenheit(k));
    }

    return 0;
}


double celsius(double t)
{
 double res;
 res = (t - 32) * 0.55;
 return res;
}

double fahrenheit(double x)
{
double result;
result= (x*1.8)+ 32;
return result;
}

