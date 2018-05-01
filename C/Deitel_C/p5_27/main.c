//Программа с помощью функции в заданном диапазоне чисел ищет простые числа
#include <stdio.h>

int simple(int x);

int main(void)
{
    int i=0;

      while(i<100)
      {
      i++;
      simple(i);
      }

    return 0;
}

int simple(int num)
{
    if ((num / num == 1) && (num % 2 != 0) && (num % 3 != 0) && (num % 5 !=0))
    {
        printf("%d ", num);
    }

    return num;
}
