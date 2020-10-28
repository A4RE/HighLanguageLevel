#include <stdio.h>
#include<locale.h>
#include <cstdlib>
int main(void)
{
	setlocale(LC_ALL, "RUS");
	int i = 0;
	int c;
	int size;
	printf("Введите размер массива ");
	scanf_s("%d", &size);
	int* a = (int*)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		{
			printf("Введите [%d] элемент массива ", i);
			scanf_s("%d", &a[i]);
		}
		if (*(a + i) < 0)
		{
			*(a + i) = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (*(a + i) % 2 == 0 && *(a + i + 1) % 2 != 0)
		{
			c = *(a + i);
			*(a + i) = *(a + i + 1);
			*(a + i + 1) = c;
		}
		else if (*(a + i) % 2 != 0 && *(a + i + 1) % 2 == 0)
		{
			c = *(a + i);
			*(a + i) = *(a + i + 1);
			*(a + i + 1) = c;
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%d ", *(a + i));
	}
	return 0;
}
