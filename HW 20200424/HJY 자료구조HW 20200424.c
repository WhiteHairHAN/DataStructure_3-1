#include <stdio.h>
#include <stdlib.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct _LISTNODE_ {
	char data;
	struct _LISTNODE_* next;
} LISTNODE;


// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct _LINKEDLIST_ {
	LISTNODE* head;
	int numOfData;
} LINKEDLIST;

/*
 * 연결 리스트 초기화, dummy head 노드 메모리 할당
 */
void InitList(LINKEDLIST* pList)
{
	pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	pList->head->next = NULL;
	pList->numOfData = 0;
}

/*
 * 연결 리스트 메모리 해제
 */
void FreeList(LINKEDLIST* pList)
{
	LISTNODE* pre = pList->head;
	LISTNODE* cur = pList->head->next;

	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;

		free(pre);
		pre = NULL;
	}
	free(pList->head);
	pList->head = NULL;
}

/*
 * 리스트의 만앞(head노드가 가리키는 첫번째 노드)에 새로운 노드 추가
 */
void InsertFirst(LINKEDLIST* pList, char x)
{
	LISTNODE* newNode = NULL;

	newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	newNode->data = x;
	newNode->next = NULL;

 	newNode->next = pList->head->next;
	pList->head->next = newNode;
	pList->numOfData += 1;			// 데이터 수 증가
}

/*
 * 리스트의 마지막에 새로운 노드 추가
 */
void InsertLast(LINKEDLIST* pList, char x)
{
	LISTNODE* pre = NULL;
	LISTNODE* cur = NULL;
	LISTNODE* newNode = NULL;

	newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	newNode->data = x;
	newNode->next = NULL;

	pre = pList->head;
	cur = pList->head->next;		// head는 초기화 과정에서 dummy로 만들어주었으므로, head->next 부터 순회
	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	//newNode->next = NULL;			// NULL임
	newNode->next = pre->next;		// NULL 임
	pre->next = newNode;
	pList->numOfData += 1;			// 데이터 수 증가
}

/*
 * data x를 가진 노드 리스트에서 찾아서 주소 반환
 */
LISTNODE* SearchNode(LINKEDLIST* pList, char x)
{
	LISTNODE* cur = NULL;
	cur = pList->head->next;

	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return cur;
}

/*
 * targer 노드를 리스트에서 삭제
 */
void DeleteNode(LINKEDLIST* pList, LISTNODE* target)
{
	LISTNODE* pre = NULL;
	LISTNODE* cur = NULL;

	if (pList->head->next == NULL || target == NULL)
	{
		fprintf(stderr, "Error, null pointer\n");
		return;
	}
	else
	{
		pre = pList->head;
		cur = pList->head->next;

		while (cur != NULL)
		{
			if (cur == target)
			{
				pre->next = cur->next;
				free(cur);
				cur = NULL;
				break;
			}
			pre = cur;
			cur = cur->next;
		}
	}
	pList->numOfData -= 1;
}

/*
 * list의 정보를 출력
 */
void PrintList(LINKEDLIST* pList)
{
	LISTNODE* cur = NULL;

	cur = pList->head->next;
	printf("L = (");
	while (cur != NULL)
	{
		printf("%c ", cur->data);
		cur = cur->next;
		if (cur != NULL)
		{
			printf(", ");
		}
	}
	printf(")\n");
}

int main()
{
	LINKEDLIST list;
	LISTNODE* find = NULL;

	InitList(&list);

 	InsertFirst(&list, 'a');
	InsertFirst(&list, 'b');


	PrintList(&list);

	InsertLast(&list, 'e');
	InsertLast(&list, 'f');


	PrintList(&list);

	find = SearchNode(&list, 'h');
	if (find == NULL) printf("찾는 데이터가 없습니다.\n");
	else printf("[%c]를 찾았습니다.\n", find->data);

	DeleteNode(&list, find);
	PrintList(&list);

	find = SearchNode(&list, 'e');
	if (find == NULL) printf("찾는 데이터가 없습니다.\n");
	else printf("[%c]를 찾았습니다.\n", find->data);

	DeleteNode(&list, find);
	PrintList(&list);

	FreeList(&list);

	return 0;
}
