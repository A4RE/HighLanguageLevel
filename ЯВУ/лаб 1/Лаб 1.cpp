#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    enum { N = 10 };
    int array[N];
    int* arrayPtr = array;

    for (int* p = arrayPtr; p != arrayPtr + N; ++p)
    {
        *p = rand() % N;
    }

    for (const int* p = arrayPtr; p != arrayPtr + N; ++p)
    {
        printf("%d ", *p);
    }

    putchar('\n'); //вывод начального массива

    int arrayChet[10];
    int* pChet = arrayChet;

    int arrayNechet[10];
    int* pNechet = arrayNechet;

    int** pChetEnd = pChet;
    int* pNechetEnd = pNechet;

    for (const int* p = array; p != arrayPtr + N; ++p)
    {
        if (*p % 2 == 0)
        {
            *pChetEnd++ = *p;
        }
        else
        {
            *pNechetEnd++ = *p;
        }
    }

    for (const int* p = pChet; p != *pChetEnd; ++p)
    {
        printf("%d ", *p);
    }

    putchar('\n'); //Вывод четных

    for (const int* p = pNechet; p != pNechetEnd; ++p)
    {
        printf("%d ", *p);
    }

    putchar('\n'); //Вывод нечетных

    return 0;
}