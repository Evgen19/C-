#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int x, y, res;

    srand (time(NULL));

    x=1+rand()%9;
    y=1+rand()%9;

    printf("Сколько будет %d умножить на %d: ", x,y);
    scanf("%d", &res);

    if(res == x*y)
    {
    printf("Очень хорошо!\n");
    }


    srand (time(NULL));

    x=1+rand()%9;
    y=1+rand()%9;

    printf("Сколько будет %d умножить на %d: ", x,y);
    scanf("%d", &res);

    if(res == x*y)
    {
    printf("Очень хорошо!\n");
    }

    else
    {
        while(res != x*y)
        {
        srand (time(NULL));
        x=1+rand()%9;
        y=1+rand()%9;

        printf("Неверно, поробуйте еще раз.\n");
        printf("Сколько будет %d умножить на %d: ", x,y);
        scanf("%d", &res);
        }
        printf("Очень хорошо!\n");
    }

    return 0;
}

