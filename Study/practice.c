#include<stdio.h>
#include<string.h>

//문제1
/*
int main(void)
{
	float A=0, B=0;

	printf("두 실수를 입력하시오: ");
	scanf("%f %f", &A, &B);

	printf("덧셈 결과: %.2lf\n뺄셈 결과: %.2lf\n곱셈결과: %.2lf\n나눗셈 결과: %.2lf\n", A+B, A - B, A * B, A / B);

	return 0;
}
*/
//문제2
/*
int main(void)
{
	int A[7] = { 0 };
	int Max, Min, Sum = 0;
	float Avg;

	for (int i = 0 ; i < 7 ; i++)
	{
		printf("정수형 데이터 입력(%d): ", i+1);
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

	printf("\n최대값: %d\n최소값: %d\n전체합: %d\n평균: %lf\n", Max, Min, Sum, Avg);

	return 0;
}
*/
//문제3-1
/*
int main(void)
{
	int a, b;

	printf("두 개의 숫자를 입력하세요: ");
	scanf("%d %d", &a, &b);

	(a>b) ? (printf("큰 수는 %d", a)) : (printf("큰 수는 %d", b));

	return 0;
}
*/
//문제3-2
/*
int main(void)
{
	int a, b, c;

	printf("세 개의 숫자를 입력하세요: ");
	scanf("%d %d %d", &a, &b, &c);

	(a > b && a > c) ? printf("큰 수는 %d", a) : (b > a && b > c) ? printf("큰 수는 %d", b) : printf("큰 수는 %d", c);

	return 0;
}
*/
//문제4-1
/*
int main(void)
{
	int number, sum = 0;
	do
	{
		printf("1이상의 정수 입력: ");
		scanf("%d", &number);

		if (number < 1)
		{
			printf("1 이상의 정수를 입력해야 합니다.\n");
		}
	} while (number < 1);

	for (int i = 0; i <= number; i++)
	{
		sum = sum + i;
	}

	printf("1부터 %d까지의 합은 %d.", number, sum);

	return 0;
}
*/
//문제4-2
/*
int main(void)
{
	int number1, number2, sum = 0;

	printf("두 개의 정수 입력: ");
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

	printf("%d과(와) %d을 포함하여 그 사이에 있는 정수들의 합: %d", number1, number2, sum);

	return 0;
}
*/
//문제5
/*
int main(void)
{
	int n1, n2, sum = 0;

	printf("두 개의 정수 입력: ");
	scanf("%d %d", &n1, &n2);

	if (n1 <= n2)
	{
		for (int i = n1; i <= n2; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				printf("%d는(은) 합에서 제외.\n", i);
				continue;
			}
			sum = sum + i;
		}
	}
	printf("\n%d과(와) %d을 포함하여 그 사이에 있는 정수들의 합: %d", n1, n2, sum);

	return 0;
}
*/
//문제6-1
/*
int main(void)
{
	int number, sum_even = 0, sum_odd = 0;

	printf("두 개의 정수 입력: ");
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

	printf("%d 이하 홀수 합 %d\n", number, sum_odd);
	printf("%d 이하 짝수 합 %d\n", number, sum_even);

	return 0;
}
*/
//문제6-2
/*
int main(void)
{
	int number, sum = 0;

	printf("2 이상 입력: ");
	scanf("%d", &number);

	for (int i = 1 ; i <= number ; i++)
	{
		sum = sum + i;
		if (sum > number) {
			printf("%d을(를) 더할 때 처음 %d을(를) 넘기 시작한다.\n", i, number);
			printf("%d를 넘기 이전의 합 : %d\n", number, sum-i);
			printf("%d를 넘은 이후의 합 : %d\n", number, sum);
			break;
		}
	}

	return 0;
}

*/
//문제7-1
/*
void gugudan_odd();
void gugudan_even();

int main(void)
{
	int number;

	do
	{
		printf("홀수 단(1), 짝수 단(2) : ");
		scanf("%d", &number);

		if (number != 1 && number != 2)
		{
			printf("잘못된 입력입니다. 1 또는 2만 입력하세요.\n");
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
//문제7-2
/*
int main(void)
{
	int number;

	printf("정수 입력: ");
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
//문제8
/*
void bubble_sort(int list[], int n);
int main(void)
{
	int i;
	int list[5] = {0};

	for (i = 0; i < 5; i++)
	{
		printf("숫자%d 입력: ", i+1);
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
//문제9
/*
int main(void)
{
	char input[100] = { 0 };
	char output[100] = { 0 };

	printf("문자열 입력 : ");
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
	printf("문자열 입력 : %s", output);

	return 0;
}

*/
//문제10
/*
int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main(void)
{
	int Kor, Eng, Mat;
	int sum;
	double avg;

	printf("세 과목의 점수 입력 : ");
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
	printf("\n\t\t===< 성적표 >===\t\n\n");
	printf("-----------------------------------------\n");
	printf("국어\t영어\t수학\t총점\t평균\n");
	printf("-----------------------------------------\n");

}*/
//문제11
/*
int Factorial(int X);

int main(void)
{
	int number = 0;
	int result = 0;
	do
	{
		printf("숫자 입력(1이상): ");
		scanf("%d", &number);
		if (number < 1)
		{
			printf("입력이 잘못되어 예상치 못한 결과를 얻었습니다. 다시 입력하세요\n\n");
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
