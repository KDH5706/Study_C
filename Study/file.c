#include <stdio.h>
#include <string.h>

//int main(void)
//{
//	FILE* fp;
//	char str[20];
//
//	fp = fopen("a.txt", "a+");
//	if (fp == NULL)
//	{
//		printf("파일이 열리지 않았습니다.\n");
//		return 1;
//	}
//
//	while (1)
//	{
//		printf("과일 이름 입력 : ");
//		scanf("%s", str);
//		if (strcmp(str, "end") == 0)
//			break;
//		else if (strcmp(str, "list") == 0)
//		{
//			fseek(fp, 0, SEEK_SET);
//			while (1)
//			{
//				fgets(str, sizeof(str), fp);
//				if (feof(fp))
//					break;
//
//				printf("%s", str);
//			}
//		}
//		else
//			fprintf(fp, "%s\n", str);
//	}
//
//
//	fclose(fp);
//
//	return 0;
//}

int main(void)
{
	FILE* ifp, *ofp;
	char name[20];

	int kor, eng, math;
	int total;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일이 열리지 않았습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("입력 파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);

		if (res == EOF)
			break;

		total = kor + eng + math;
		avg = total / 3.0;
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}


	fclose(ifp);
	fclose(ofp);

	return 0;
}