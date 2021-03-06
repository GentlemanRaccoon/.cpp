#include <iostream>

// додаткова бібліотека 
#include <time.h>

using namespace std;

int main()
{
	// генератор випадкових чисел
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// розміри матрицi
	int A[100][100];
	int n, k, i;
	char z;

	n = 6;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tЗаповнення матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i]) < 10 || abs(A[k][i]) > 99);
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}

		printf("\n\tКопiя матрицi A[%2i][%2i] цiлими двозначними числами. \n\n", n, n);

		long dob = 1;
		int poz, neg, sum, p, min, max, B[10000];

		poz = 0;
		neg = 0;
		sum = 0;
		p = 0;

		for (int j = 0; j < n; j++) B[j] = 0;

		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				  if (k < i|| i >= n / 2) printf("%5i", A[k][i]);							
				else											
				{
					printf("    *");
					B[p] = A[k][i];
					p++;

					if (A[k][i] > 0)
					{
						poz++;
						sum += A[k][i];
					}
					else
					{
						neg++;
						dob *= A[k][i];
					}
				}
			}
			cout << "\n";
		}

		min = B[0];
		for (int j = 0; j < p; j++)
		{
			if (B[j] < min) min = B[j];
		}

		max = B[0];
		for (int j = 0; j < p; j++)
		{
			if (B[j] > max) max = B[j];
		}

		printf("\n\n\tдодатних: %i", poz);
		printf("\n\tвiд'ємних: %i", neg);
		printf("\n\tсума додатних: %i", sum);
		printf("\n\tдобуток вiд'ємних: %i", dob);
		printf("\n\tнайбiльший: %i", max);
		printf("\n\tнайменший: %i", min);

		cout << "\n\n\tПродовжити (y/n)? ";
		cin >> z;
	} while (z != 'n');

	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}
