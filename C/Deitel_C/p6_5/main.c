/*�������������� �������� ������� s
������� ������ ������� �� 2 �� 20*/
#include <stdio.h>

#define SIZE 10

int main(int argc, char *argv[])
{
    int s[SIZE], j;

    for(j=0; j <= SIZE-1; j++) /*������������� ��������*/
        s[j]=2+2*j;

    printf("%s%13s\n", "Element", "Value");

    for(j=0; j<=SIZE-1; j++)/*������� ��������*/
        printf("%7d%13d\n", j, s[j]);

    return 0;
}
