/*ћоделирует бросание шистигранной кости 6000 раз*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7

int main()
{
    int face, roll, frequency[SIZE] = {0};
    srand(time(NULL));
    for(roll=1; roll<=6000; roll++)
    {
        face = rand() % 6 + 1;
        ++frequency[face];
    }
    printf("%s%17s\n", "Face", "Freduency");

    for(face=1; face<=SIZE-1; face++)
    printf("%4d%17d\n", face, frequency[face]);

    return 0;
}
