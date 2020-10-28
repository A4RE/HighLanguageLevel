#include <stdio.h>
#include <locale.h>
int main(void)
{
	int a, b;
	setlocale(LC_ALL, "Russian");
	printf("Введите первое число\n");
	scanf_s("%d", &a);
	printf("Введите второе число\n");
	scanf_s("%d", &b);
	if (a == b)
	{

		printf("Числа равны");
	}
	else
	{
		if (a > b)
		{
			printf("Первое число больше второго");
		}
		if (a < b)
		{
			printf("Второе число больше первого");
		}
	}
	return 0;
}