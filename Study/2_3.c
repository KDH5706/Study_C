#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int ary[5] = { 1,2,3,4,5 };
	int* pa, * pb, * pc;
	int i;
	pa = (int*)malloc(sizeof(ary));
	if (pa == NULL)
		exit(1);
	else
	{
		for (i = 0; i < 5; i++)
			pa[i] = ary[i];
	}

	pb = (int*)calloc(pa[3], sizeof(int));
	pc = (int*)realloc(NULL, pa[4]);

	printf("%d,%d,%d", sizeof(pa), sizeof(pb), sizeof(pc));

	free(pa);
	free(pb);
	free(pc);

	return 0;
}