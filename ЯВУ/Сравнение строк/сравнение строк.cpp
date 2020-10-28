#include <stdio.h>
#include <locale.h>

#define MAXLINE 1000

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int i;
	i = 0;
	char str1[MAXLINE];
	char str2[MAXLINE];
	printf("Введите первую строку:\n");
	gets_s(str1);
	printf("Введите вторую строку:\n");
	gets_s(str2);

	do
	{
		i++;
	} while (str1[i] != '\0' && str2[i] != '\0');

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		printf("Длины строк равны");
	}
	else if (str2[i] == '\0')
	{
		printf("Первая строка больше второй");
	}
	else if (str1[i] == '\0')
	{
		printf("Вторая строка больше первой");
	}

	return 0;
}