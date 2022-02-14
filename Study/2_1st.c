#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define LENGTH_OF_STRING 50
#define SCALE_OF_DB 10

typedef enum { false, true } bool;

typedef struct {
	char bookTitle[LENGTH_OF_STRING];
	char bookPub[LENGTH_OF_STRING];
	int bookPrice;
}bookInfo;

bookInfo* pointer_Sort_bookList[SCALE_OF_DB];

typedef struct _linked_list
{
	bookInfo* pointer_bookList_address;

	struct _linked_list* next;
}linked_list;

int first_empty = 0;

int InsertList(bookInfo* bookPtr);

void InitSortList(void);
void PrintSortList(void);

void SortByTitle(void);
void SortByPubName(void);
void SortByPrice(void);

int main(void)
{

	int key_of_menu = 0;
	//bookInfo DB[SCALE_OF_DB] = { 0 };
	bookInfo DB[SCALE_OF_DB] = {
		{"������","�Ѻ�", 20000},
		{"������","����", 21000},
		{"������","����", 17000},
		{"������","����", 31000},
		{"�ٰ���","���", 12000},
	};

	while (true)
	{
		for (int i = 0; i < SCALE_OF_DB; i++)
		{
			pointer_Sort_bookList[i] = &DB[i];
		}

		char input;

		system("cls");
		printf("\t/*�������� ���α׷�*/\n\n");
		printf("1. ���� ���� ��ü ���\n");
		printf("2. ���� ���� ����\n");
		printf("3. ���� ���� ���(���� Ÿ��Ʋ �� ����)\n");
		printf("4. ���� ���� ���(���� ���ǻ� �� �� ����)\n");
		printf("5. ���� ���� ���(���� ���� �� ����)\n");
		printf("6. ���α׷� ����\n\n");
		printf("�޴��� �����ϼ���. >>> ");
		
		scanf(" %c", &input);
		if ('1' <= input && input <= '6')
		{
			key_of_menu = input - '1' + 1;
		}
		else
		{
			printf("�Է��� �߸��ƽ��ϴ�.\n");
			Sleep(1000);
			continue;
		}

		switch (key_of_menu)
		{
		case 1:
			PrintSortList();
			break;

		case 2:
		{
			int state = InsertList(DB);
			switch (state)
			{
			case -1:
				printf("����� ������ �����ϴ�.\n");
				break;
			default:
				printf("%d ��° �ű� �����Ͱ� ����Ǿ����ϴ�.", state);
				break;
			}
			Sleep(1500);
			break;
		}
		case 3:
			SortByTitle();
			break;

		case 4:
			SortByPubName();
			break;

		case 5:
			SortByPrice();
			break;

		case 6:
			printf("\n����ڿ� ���� ���α׷��� ����Ǿ����ϴ�.\n");
			exit(0);
		}

	}
	return 0;
}

void PrintSortList()
{

	printf("\n����\tŸ��Ʋ\t���ǻ�\t����\n\n");
	for (int index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") != 0)
		{
			printf("%d\t", index);
			printf("%s\t", pointer_Sort_bookList[index]->bookTitle);
			printf("%s\t", pointer_Sort_bookList[index]->bookPub);
			printf("%d\n", pointer_Sort_bookList[index]->bookPrice);
		}
	}

	Sleep(3000);
}

int InsertList(bookInfo* bookPtr)
{
	bookInfo buffer = { 0 };

	printf("���� Ÿ��Ʋ ���� �Է��ϼ���. >>> ");
	while (getchar() != '\n');
	scanf("%[^\n]s", &buffer.bookTitle);
	printf("���ǻ� ���� �Է��ϼ���. >>> ");
	while (getchar() != '\n');
	scanf("%[^\n]s", &buffer.bookPub);
	printf("���� ������ �Է��ϼ���. >>> ");
	scanf("%d", &buffer.bookPrice);

	//���� ���� �迭���� Ž�� ��ġ
	int index = 0;

	//�ű� �����Ͱ� ��ϵ� �迭�� ��ġ
	int inputIdx = first_empty;

	if (first_empty >= SCALE_OF_DB)
		return -1; // -1�� �Է� ���и� �ǹ�

	for (index = 0; index < first_empty; index++)
	{
		if (strcmp(bookPtr[index].bookTitle, buffer.bookTitle) > 0)
		{
			inputIdx = index;
			break;
		}
	}

	/** �ű� ���� ����� ���� �迭 ���� ��ġ�� ������ Ȯ�� **/
	for (index = first_empty; index > inputIdx; index--)
		bookPtr[index] = bookPtr[index - 1];

	/** ���ο� ������ �Է� **/
	bookPtr[inputIdx] = buffer;

	first_empty++;

	return first_empty;
}

void SortByTitle()
{
	//pointer_Sort_bookList
	int index = 0;
	bookInfo *temp = { 0 };

	/*DB �� ������ ������ �� �κ��� �����͸� �̿��Ͽ� ã��(���� DB�� Ÿ��Ʋ ������������ �״�� ����)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'����ü ������ �迭�� �ּҰ� ����Ű�� ��'�� �̿��Ͽ� '����ü ������ �迭'�� ���� Ÿ��Ʋ ������ ����*/
	for (int i = index-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(pointer_Sort_bookList[j]->bookTitle, pointer_Sort_bookList[j+1]->bookTitle) > 0)
			{
				temp = pointer_Sort_bookList[j];
				pointer_Sort_bookList[j] = pointer_Sort_bookList[j+1];
				pointer_Sort_bookList[j + 1] = temp;
			}
		}
	}

	PrintSortList();
}

void SortByPubName()
{
	//pointer_Sort_bookList
	int index = 0;
	bookInfo* temp = { 0 };

	/*DB �� ������ ������ �� �κ��� �����͸� �̿��Ͽ� ã��(���� DB�� Ÿ��Ʋ ������������ �״�� ����)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'����ü ������ �迭�� �ּҰ� ����Ű�� ��'�� �̿��Ͽ� '����ü ������ �迭'�� ���� ���ǻ� ������ ����*/
	for (int i = index - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strcmp(pointer_Sort_bookList[j]->bookPub, pointer_Sort_bookList[j + 1]->bookPub) > 0)
			{
				temp = pointer_Sort_bookList[j];
				pointer_Sort_bookList[j] = pointer_Sort_bookList[j + 1];
				pointer_Sort_bookList[j + 1] = temp;
			}
		}
	}

	PrintSortList();
}

void SortByPrice()
{
	//pointer_Sort_bookList
	int index = 0;
	bookInfo* temp = { 0 };

	/*DB �� ������ ������ �� �κ��� �����͸� �̿��Ͽ� ã��(���� DB�� Ÿ��Ʋ ������������ �״�� ����)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'����ü ������ �迭�� �ּҰ� ����Ű�� ��'�� �̿��Ͽ� '����ü ������ �迭'�� ���� ���ǻ� ������ ����*/
	for (int i = index - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (pointer_Sort_bookList[j]->bookPrice > pointer_Sort_bookList[j + 1]->bookPrice)
			{
				temp = pointer_Sort_bookList[j];
				pointer_Sort_bookList[j] = pointer_Sort_bookList[j + 1];
				pointer_Sort_bookList[j + 1] = temp;
			}
		}
	}

	PrintSortList();
}


