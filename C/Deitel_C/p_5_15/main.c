#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b);

int main(void)
{
    double num1, num2;
    printf("Введите значения катетов ");
    scanf ("%lf %lf", &num1, &num2);
    printf("Значение гипотенузы равно %0.2f\n", hypotenuse(num1, num2));
    return 0;
}

double hypotenuse(double x, double y)
{
    double c, result;

    c= (x*x)+(y*y);
    result = sqrt(c);

    return result;
}
