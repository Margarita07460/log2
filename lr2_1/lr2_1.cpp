#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	//clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r, elem_c;
	int n = 1000;
	int** a;
	int** b;
	int** c;

	//int a[200][200], b[200][200], c[200][200], elem_c;

	while (n <= 10000) {
		printf(" % d -> ", n);
		a = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{

			a[i] = (int*)malloc(n * sizeof(int));
		}

		b = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++) {

			b[i] = (int*)malloc(n * sizeof(int));
		}

		c = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{

			c[i] = (int*)malloc(n * sizeof(int));
		}

		srand(time(NULL)); // инициализируем параметры генератора случайных чисел
		while (i < n)
		{
			while (j < n)
			{
				a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
				j++;
			}
			i++;
		}
		srand(time(NULL)); // инициализируем параметры генератора случайных чисел
		i = 0; j = 0;
		while (i < n)
		{
			while (j < n)
			{
				b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
				j++;
			}
			i++;
		}
		clock_t start = clock();

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				elem_c = 0;
				for (r = 0; r < n; r++)
				{
					elem_c = elem_c + a[i][r] * b[r][j];
					c[i][j] = elem_c;
				}
			}
		}
		clock_t end = clock();

		printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);

		n = n + 1000;

	}
	return(0);
}

