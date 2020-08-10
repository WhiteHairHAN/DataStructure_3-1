#include <stdio.h>
#include <stdlib.h>

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct _LISTNODE_ {
	char data;
	struct _LISTNODE_* next;
} LISTNODE;


// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct _LINKEDLIST_ {
	LISTNODE* head;
	int numOfData;
} LINKEDLIST;

/*
 * ���� ����Ʈ �ʱ�ȭ, dummy head ��� �޸� �Ҵ�
 */
void InitList(LINKEDLIST* pList)
{
	pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	pList->head->next = NULL;
	pList->numOfData = 0;
}

/*
 * ���� ����Ʈ �޸� ����
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
 * ����Ʈ�� ����(head��尡 ����Ű�� ù��° ���)�� ���ο� ��� �߰�
 */
void InsertFirst(LINKEDLIST* pList, char x)
{
	LISTNODE* newNode = NULL;

	newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	newNode->data = x;
	newNode->next = NULL;

 	newNode->next = pList->head->next;
	pList->head->next = newNode;
	pList->numOfData += 1;			// ������ �� ����
}

/*
 * ����Ʈ�� �������� ���ο� ��� �߰�
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
	cur = pList->head->next;		// head�� �ʱ�ȭ �������� dummy�� ������־����Ƿ�, head->next ���� ��ȸ
	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	//newNode->next = NULL;			// NULL��
	newNode->next = pre->next;		// NULL ��
	pre->next = newNode;
	pList->numOfData += 1;			// ������ �� ����
}

/*
 * data x�� ���� ��� ����Ʈ���� ã�Ƽ� �ּ� ��ȯ
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
 * targer ��带 ����Ʈ���� ����
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
 * list�� ������ ���
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
	if (find == NULL) printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%c]�� ã�ҽ��ϴ�.\n", find->data);

	DeleteNode(&list, find);
	PrintList(&list);

	find = SearchNode(&list, 'e');
	if (find == NULL) printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%c]�� ã�ҽ��ϴ�.\n", find->data);

	DeleteNode(&list, find);
	PrintList(&list);

	FreeList(&list);

	return 0;
}
