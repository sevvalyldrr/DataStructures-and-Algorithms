#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20


struct StackNode {
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data)
{
	struct StackNode* stackNode =(struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	
	return stackNode;
}

int stackIsFull(struct StackNode* root)
{	
	int count =0;
	int data;
	struct StackNode* stackNode =(struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;

	for(int i=0; i<=MAXSIZE; i++)
	{
		if(root->next != NULL)
		{
			count++;
			struct StackNode* temp = root;
			root = (root)->next;
			data = temp->data;
			free(temp);
		}
	}
	
	if(count+1 >= MAXSIZE)
	{
		printf("evet fulldur");		
	}
	else if (count < MAXSIZE)
	{
		printf("full degildir");
	}
}

int isEmpty(struct StackNode* root)
{
	return !root;
}

void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
	{
		return INT_MIN;
	}

	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
	{
		return INT_MIN;
	}

	return root->data;
}

int main()
{
	struct StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	push(&root, 55);
	
	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(root));

	stackIsFull(root);

	return 0;
}
