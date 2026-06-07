#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node node_t;

typedef struct Node
{
	char* string;
	node_t* prev;
	node_t* next;
} node_t;

typedef struct ll
{
	node_t* head;
	node_t* end;
} ll_t;


int sizeOfStr(char* str)
{
	if(str == NULL || str[0] == '\0')
	{
		return 0;
	}
	int size = 0;
	while(str[size] != '\0')
	{
		size++;
	}
	return size;
}

void testSizeOfStr()
{
	if(sizeOfStr("hello") != 5) 
	{
		printf("Invalid result from sizeOfStr");
	} else {
		printf("Nigga stupid");
	}
}

ll_t *createList()
{
	ll_t* list = (ll_t*)malloc(sizeof(ll_t));
	list->head = NULL;
	list->end = NULL;
	return list;
}

node_t* createNode(char* str)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	int k = sizeOfStr(str);
	char* buffer = (char*)malloc(sizeof(char)* (k+1));
	buffer[k] = '\0';
	int p = sprintf(buffer, "%s", str);
	if(p != k)
	{
		printf("Buffer overflow in createNode");
		return NULL;
	}
	node->string = buffer;
	node->next = NULL;
	node->prev = NULL;
	return node;
}


ll_t *fillList(char* str, ll_t *list)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	int k = sizeOfStr(str);
	char* buffer = (char*)malloc(sizeof(char)* (k+1));
	buffer[k] = '\0';
	int p = sprintf(buffer, "%s", str);
	if(p != k)
	{
		printf("Buffer overflow in createNode");
		return NULL;
	}
	node->string = buffer;
	if(list->head == NULL) // Means this is new list
	{
		list->head = node;
		list->end = node;
		node->prev = NULL;
		node->next = NULL;

		return list;
	}
	else
	{
		node->prev = list->end;
		list->end->next = node;
		list->end = node;
		node->next = NULL;
		return list;
	}
	
}

void printList(ll_t *list)
{
	node_t* node = list->head;
	if(node == NULL)
	{
		printf("Empty Node\n");
		return;
	}
	while(node != NULL)
	{
		printf("%s",node->string);
		node = node->next;
	}
}

void printListRev(ll_t *list)
{
	node_t* node = list->end;
	if(node == NULL)
	{
		printf("Empty Node\n");
		return;
	}
	while(node != NULL)
	{
		printf("%s",node->string);
		node = node->prev;
	}
}

int lenOfList(ll_t *list)
{
	node_t *node = list->head;
	int size = 0;
	while(node != NULL)
	{
		size++;
		node = node->next;
		
	}
	return size;
}

void insert(char* str, int pos, ll_t *list)
{
	node_t *node = list->head;
	int rpos = pos;
	int size = lenOfList(list);
	if(rpos > size)
	{
		fillList(str, list);
		return;
	}
	while(rpos > 0)
	{
		rpos--;
		node = node->next;
	}
	node_t* temp = node->next;
	node_t* ass = createNode(str);
	if(temp == NULL)
		list->end = ass;
	node->next = ass;
	ass->next = temp;
	ass->prev = node;
	temp->prev = ass;
}
typedef struct MetaNode {
	node_t* node;
	int pos;
} metanode_t;

metanode_t *findNode(char* str, ll_t *list, int spos)
{
	node_t *node = list->head;
	int count = 0;
	while(spos > 0)
	{
		node = node->next;
		spos--;
	}
	metanode_t* mn = (metanode_t*)malloc(sizeof(metanode_t));
	while(node != NULL)
	{
		if(strcmp(node->string, str) == 0)
		{
			//we have our first fined;
			mn->node = node;
			mn->pos = count;
			return mn;
		}
		node = node->next;
		count++;
	}
	mn->node = NULL;
	mn->pos = -1;
	return mn;
}


void deleteNode(char* str, ll_t* list)
{
	metanode_t* mn = findNode(str, list, 0);
	if(mn->pos == -1)
	{
		printf("Node doesn't exist");
		return;
	}
	node_t* node = mn->node;
	if(node == list->head)
	{
		// We are deleting head
		list->head = node->next;
		node->next = NULL;
		free(node->string);
		free(node);
		return;
	}
	if(node == list->end)
	{
		list->end = node->prev;
		list->end->next = NULL;
		node->prev = NULL;
		free(node->string);
		free(node);
		return;

	}
	node->prev->next = node->next;
	node->next->prev = node->prev;  
	node->prev = NULL;
	node->next = NULL;
	free(node->string);
	free(node);
}


int main(void) 
{
	ll_t *list = createList();
	fillList("Good", list);
	fillList(" Oh", list);
	printf("Looks");
	printf("\n");
	printList(list);
	metanode_t *mn = findNode(" Oh", list, 0);
	printf("\n");
	printf("%d",mn->pos);
	printf("\n");
	printListRev(list);
	printf("\n");
	printf("%d", lenOfList(list));
	printf("\n");
	printf("\n");
	deleteNode(" Oh", list);
	printf("\n");
	printList(list);
	printf("\n");
	printf("%d", lenOfList(list));
}
