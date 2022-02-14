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
		{"가가가","한빛", 20000},
		{"가가나","세움", 21000},
		{"가나라","연원", 17000},
		{"나가다","진원", 31000},
		{"다가가","담앤", 12000},
	};

	while (true)
	{
		for (int i = 0; i < SCALE_OF_DB; i++)
		{
			pointer_Sort_bookList[i] = &DB[i];
		}

		char input;

		system("cls");
		printf("\t/*도서관리 프로그램*/\n\n");
		printf("1. 도서 정보 전체 출력\n");
		printf("2. 도서 정보 저장\n");
		printf("3. 도서 정보 출력(도서 타이틀 별 정렬)\n");
		printf("4. 도서 정보 출력(도서 출판사 명 별 정렬)\n");
		printf("5. 도서 정보 출력(도서 가격 별 정렬)\n");
		printf("6. 프로그램 종료\n\n");
		printf("메뉴를 선택하세요. >>> ");
		
		scanf(" %c", &input);
		if ('1' <= input && input <= '6')
		{
			key_of_menu = input - '1' + 1;
		}
		else
		{
			printf("입력이 잘못됐습니다.\n");
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
				printf("저장될 공간이 없습니다.\n");
				break;
			default:
				printf("%d 번째 신규 데이터가 저장되었습니다.", state);
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
			printf("\n사용자에 의해 프로그램이 종료되었습니다.\n");
			exit(0);
		}

	}
	return 0;
}

void PrintSortList()
{

	printf("\n순서\t타이틀\t출판사\t가격\n\n");
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

	printf("도서 타이틀 명을 입력하세요. >>> ");
	while (getchar() != '\n');
	scanf("%[^\n]s", &buffer.bookTitle);
	printf("출판사 명을 입력하세요. >>> ");
	while (getchar() != '\n');
	scanf("%[^\n]s", &buffer.bookPub);
	printf("도서 가격을 입력하세요. >>> ");
	scanf("%d", &buffer.bookPrice);

	//도서 관리 배열에서 탐색 위치
	int index = 0;

	//신규 데이터가 등록될 배열의 위치
	int inputIdx = first_empty;

	if (first_empty >= SCALE_OF_DB)
		return -1; // -1은 입력 실패를 의미

	for (index = 0; index < first_empty; index++)
	{
		if (strcmp(bookPtr[index].bookTitle, buffer.bookTitle) > 0)
		{
			inputIdx = index;
			break;
		}
	}

	/** 신규 도서 등록을 위한 배열 삽입 위치의 공간을 확보 **/
	for (index = first_empty; index > inputIdx; index--)
		bookPtr[index] = bookPtr[index - 1];

	/** 새로운 데이터 입력 **/
	bookPtr[inputIdx] = buffer;

	first_empty++;

	return first_empty;
}

void SortByTitle()
{
	//pointer_Sort_bookList
	int index = 0;
	bookInfo *temp = { 0 };

	/*DB 상 실질적 데이터 끝 부분을 포인터를 이용하여 찾기(기존 DB는 타이틀 오름차순으로 그대로 보존)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'구조체 포인터 배열의 주소가 가르키는 값'을 이용하여 '구조체 포인터 배열'을 도서 타이틀 순으로 정렬*/
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

	/*DB 상 실질적 데이터 끝 부분을 포인터를 이용하여 찾기(기존 DB는 타이틀 오름차순으로 그대로 보존)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'구조체 포인터 배열의 주소가 가르키는 값'을 이용하여 '구조체 포인터 배열'을 도서 출판사 순으로 정렬*/
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

	/*DB 상 실질적 데이터 끝 부분을 포인터를 이용하여 찾기(기존 DB는 타이틀 오름차순으로 그대로 보존)*/
	for (index = 0; index < SCALE_OF_DB; index++)
	{
		if (strcmp(pointer_Sort_bookList[index]->bookTitle, "") == 0)
		{
			break;
		}
	}

	/*'구조체 포인터 배열의 주소가 가르키는 값'을 이용하여 '구조체 포인터 배열'을 도서 출판사 순으로 정렬*/
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


