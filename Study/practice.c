#include<stdio.h>
#include<string.h>

//����1
/*
int main(void)
{
	float A=0, B=0;

	printf("�� �Ǽ��� �Է��Ͻÿ�: ");
	scanf("%f %f", &A, &B);

	printf("���� ���: %.2lf\n���� ���: %.2lf\n�������: %.2lf\n������ ���: %.2lf\n", A+B, A - B, A * B, A / B);

	return 0;
}
*/
//����2
/*
int main(void)
{
	int A[7] = { 0 };
	int Max, Min, Sum = 0;
	float Avg;

	for (int i = 0 ; i < 7 ; i++)
	{
		printf("������ ������ �Է�(%d): ", i+1);
		scanf("%d", &A[i]);
	}

	Max = A[0];
	Min = A[0];

	for (int i = 0; i < 7; i++)
	{
		if (A[i] >= Max)
		{
			Max = A[i];
		}
		if (A[i] <= Min)
		{
			Min = A[i];
		}

		Sum = Sum + A[i];
	}

	Avg = (float)(Sum) / 7;

	printf("\n�ִ밪: %d\n�ּҰ�: %d\n��ü��: %d\n���: %lf\n", Max, Min, Sum, Avg);

	return 0;
}
*/
//����3-1
/*
int main(void)
{
	int a, b;

	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%d %d", &a, &b);

	(a>b) ? (printf("ū ���� %d", a)) : (printf("ū ���� %d", b));

	return 0;
}
*/
//����3-2
/*
int main(void)
{
	int a, b, c;

	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%d %d %d", &a, &b, &c);

	(a > b && a > c) ? printf("ū ���� %d", a) : (b > a && b > c) ? printf("ū ���� %d", b) : printf("ū ���� %d", c);

	return 0;
}
*/
//����4-1
/*
int main(void)
{
	int number, sum = 0;
	do
	{
		printf("1�̻��� ���� �Է�: ");
		scanf("%d", &number);

		if (number < 1)
		{
			printf("1 �̻��� ������ �Է��ؾ� �մϴ�.\n");
		}
	} while (number < 1);

	for (int i = 0; i <= number; i++)
	{
		sum = sum + i;
	}

	printf("1���� %d������ ���� %d.", number, sum);

	return 0;
}
*/
//����4-2
/*
int main(void)
{
	int number1, number2, sum = 0;

	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &number1, &number2);

	if (number1 <= number2)
	{
		for (int i = number1; i <= number2; i++)
		{
			sum = sum + i;
		}
	}
	else
	{
		for (int i = number2; i <= number1; i++)
		{
			sum = sum + i;
		}
	}

	printf("%d��(��) %d�� �����Ͽ� �� ���̿� �ִ� �������� ��: %d", number1, number2, sum);

	return 0;
}
*/
//����5
/*
int main(void)
{
	int n1, n2, sum = 0;

	printf("�� ���� ���� �Է�: ");
	scanf("%d %d", &n1, &n2);

	if (n1 <= n2)
	{
		for (int i = n1; i <= n2; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				printf("%d��(��) �տ��� ����.\n", i);
				continue;
			}
			sum = sum + i;
		}
	}
	printf("\n%d��(��) %d�� �����Ͽ� �� ���̿� �ִ� �������� ��: %d", n1, n2, sum);

	return 0;
}
*/
//����6-1
/*
int main(void)
{
	int number, sum_even = 0, sum_odd = 0;

	printf("�� ���� ���� �Է�: ");
	scanf("%d", &number);

	for (int i = 1 ; i <= number ; i++)
	{
		if (i % 2 == 0)
		{
			sum_even = sum_even + i;
		}
		else
		{
			sum_odd = sum_odd + i;
		}
	}

	printf("%d ���� Ȧ�� �� %d\n", number, sum_odd);
	printf("%d ���� ¦�� �� %d\n", number, sum_even);

	return 0;
}
*/
//����6-2
/*
int main(void)
{
	int number, sum = 0;

	printf("2 �̻� �Է�: ");
	scanf("%d", &number);

	for (int i = 1 ; i <= number ; i++)
	{
		sum = sum + i;
		if (sum > number) {
			printf("%d��(��) ���� �� ó�� %d��(��) �ѱ� �����Ѵ�.\n", i, number);
			printf("%d�� �ѱ� ������ �� : %d\n", number, sum-i);
			printf("%d�� ���� ������ �� : %d\n", number, sum);
			break;
		}
	}

	return 0;
}

*/
//����7-1
/*
void gugudan_odd();
void gugudan_even();

int main(void)
{
	int number;

	do
	{
		printf("Ȧ�� ��(1), ¦�� ��(2) : ");
		scanf("%d", &number);

		if (number != 1 && number != 2)
		{
			printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n");
		}
	}while(number != 1 && number != 2);

	switch (number)
	{
	case 1:
		gugudan_odd();
		break;
	case 2:
		gugudan_even();
		break;
	default:
		break;
	}

	return 0;
}

void gugudan_odd()
{
	for (int i = 3; i <= 9; i = i + 2)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%dX%d=%d\n", i, j, i*j);
		}
		printf("\n");
	}
}

void gugudan_even()
{

	for (int i = 2; i <= 9; i = i + 2)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%dX%d=%d\n", i, j, i*j);
		}
		printf("\n");
	}
}

*/
//����7-2
/*
int main(void)
{
	int number;

	printf("���� �Է�: ");
	scanf("%d", &number);

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if ((i * j - k) == number)
				{
					printf("(%d)x(%d)-(%d) = (%d)\n", i, j, k, (i * j - k));
				}
			}
		}
	}

	return 0;
}
*/
//����8
/*
void bubble_sort(int list[], int n);
int main(void)
{
	int i;
	int list[5] = {0};

	for (i = 0; i < 5; i++)
	{
		printf("����%d �Է�: ", i+1);
		scanf("%d", &list[i]);
	}

	bubble_sort(list, (sizeof(list)/sizeof(list[0])));

	for (i = 0; i < 5; i++) {
		printf("%d", list[i]);
	}

	return 0;
}
/*
void bubble_sort(int list[], int n) {
	int i, j, temp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
*/
//����9
/*
int main(void)
{
	char input[100] = { 0 };
	char output[100] = { 0 };

	printf("���ڿ� �Է� : ");
	gets(input);

	for (int i = 0; input[i] != 0; i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z') {
			output[i] = input[i] + 32;
		}
		else if (input[i] >= 'a' && input[i] <= 'z') {
			output[i] = input[i] - 32;
		}
		else
		{
			output[i] = input[i];
		}
	}
	printf("���ڿ� �Է� : %s", output);

	return 0;
}

*/
//����10
/*
int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main(void)
{
	int Kor, Eng, Mat;
	int sum;
	double avg;

	printf("�� ������ ���� �Է� : ");
	scanf("%d %d %d", &Kor, &Eng, &Mat);

	sum = total(Kor, Eng, Mat);
	avg = average(sum);

	print_title();
	printf("%d\t%d\t%d\t%d\t%.1lf\n", Kor, Eng, Mat, sum, avg);

	return 0;
}

int total(int kor, int eng, int mat)
{
	int total;
	total = kor + eng + mat;

	return total;
}

double average(int tot)
{
	double avg;
	avg = (double)(tot)/3;

	return avg;
}

void print_title(void)
{
	printf("\n\t\t===< ����ǥ >===\t\n\n");
	printf("-----------------------------------------\n");
	printf("����\t����\t����\t����\t���\n");
	printf("-----------------------------------------\n");

}*/
//����11
/*
int Factorial(int X);

int main(void)
{
	int number = 0;
	int result = 0;
	do
	{
		printf("���� �Է�(1�̻�): ");
		scanf("%d", &number);
		if (number < 1)
		{
			printf("�Է��� �߸��Ǿ� ����ġ ���� ����� ������ϴ�. �ٽ� �Է��ϼ���\n\n");
		}
	} while(number < 1);

	result = Factorial(number);

	printf("%d! = %d", number, result);
	return 0;
}

int Factorial(int X)
{
	int result = 1;

	for (int i = 1; i <= X; i++)
	{
		result *= i;
	}

	return result;
}
*/
