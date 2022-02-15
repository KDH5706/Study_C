#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:6031)

//
//void print_str(char* *pps, int cnt);
//
//int main(void)
//{
//	char* ptr_ary[] = {"apple","banana","kiwi"};
//	int count;
//
//
//	for (int i = 0; i < 3; i++)
//		printf("%d\t", &ptr_ary[i]);
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//		printf("%d\t", ptr_ary[i]);
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//		printf("%s\t", ptr_ary[i]);
//	printf("\n");
//
//	for (int i = 0; i < 3; i++)
//		printf("%c\t", *ptr_ary[i]);
//	printf("\n\n");
//
//
//	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
//
//	print_str(ptr_ary, count);
//
//	return 0;
//}
//
//void print_str(char** pps, int cnt)
//{
//	int i;
//
//
//	for (i = 0; i < cnt; i++)
//		printf("%d\t", &pps[i]);
//	printf("\n");
//
//	for (i = 0; i < cnt; i++)
//		printf("%d\t", pps[i]);
//	printf("\n");
//
//	for (i = 0; i < cnt; i++)
//		printf("%s\t", pps[i]);
//	printf("\n");
//
//	for (i = 0; i < cnt; i++)
//		printf("%c\t", *pps[i]);
//	printf("\n");
//}

//int add(int a, int b) { return (a + b); }
//int sub(int a, int b) { return (a - b); }
//int mul(int a, int b) { return (a * b); }
//
//int main(void)
//{
//	int (*pary[3])(int, int) = { add, sub, mul };
//	int i, res = 0;
//
//	for (i = 0; i < 3; i++)
//		res += pary[i](2, 1);
//
//	printf("%d", res);
//
//	return 0;
//}

//int main(void)
//{
//	int* prime;
//	int num;
//	int check = 1;
//
//	printf("숫자 입력 : ");
//	scanf("%d", &num);
//
//	prime = (int*)calloc(num , sizeof(int));
//	if (prime == NULL)
//		exit(1);
//
//	for (int i = 0; i < num-1; i++)
//	{
//		prime[i] = i + 2;
//		check = 1;
//
//		if (prime[i] != 2)
//		{
//			for (int j = 2; j < prime[i]; j++)
//			{
//				if (prime[i] % j == 0)
//				{
//					printf("   X");
//					check = 0;
//					break;
//				}
//			}
//		}
//
//		if (check == 1)
//			printf("%4d", prime[i]);
//
//		if (i % 5 == 4)
//			printf("\n");
//	}
//
//	free(prime);
//
//	return 0;
//}

//int main(void)
//{
//	char ani[20];
//	char why[80];
//	printf("좋아하는 동물 : ");
//	scanf("%s", &ani);
//	getchar();
//	printf("좋아하는 이유 : ");
//	fgets(why, sizeof(why), stdin);
//	printf("%s is %s", ani, why);
//	return 0;
//}

//int main(void)
//{
//	char* ps = "applepie";
//	ps += 5;
//	printf("%s", ps);
//
//	return 0;
//}

