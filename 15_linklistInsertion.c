#include <stdio.h>
#include<stdlib.h>

//Prototype of structure.
struct Node
{
	int data;
	struct Node *link;
};

void linklistTraversal(struct Node* ptr)
{
	while(ptr != NULL)
	{
		printf("%d-->",ptr-> data);
		ptr=ptr->link;
	}
	printf("Null\n");
}

//Insert at the beginning
struct Node * insertAtFirst(struct Node * head,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr-> link = head;
	ptr-> data = data;
	return ptr;
}

//Insert in between
struct Node * insertAtIndex(struct Node *head,int data,int index)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node * temp = head;
	int i=0;
	while(i!=index-1)
	{
		temp = temp ->link;
		i++;

	}
	ptr->data=data;
	ptr ->link = temp->link;
	temp -> link = ptr;
	return head;
}

struct Node * insertAtEnd(struct Node *head,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	struct Node *temp = head;
	while(temp->link != NULL)
	{
		temp=temp->link;
	}
	temp->link=ptr;
	ptr->link=NULL;
	return head;
}

//Deletion at first
struct Node * deleteAtFirst(struct Node* head)
{
	if(head==NULL)
		return 0;
	else
	{
		struct Node * temp= head;
		head = temp->link;
		free(temp);
		return head;
	}
}

struct Node * deleteAtEnd(struct Node *head)
{
	
}
//Main Function
int main(int argc, char const *argv[])
{
	struct Node * head;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;

	head =(struct Node *)malloc(sizeof(struct Node));
	second =(struct Node *)malloc(sizeof(struct Node));
	third =(struct Node *)malloc(sizeof(struct Node));
	fourth =(struct Node *)malloc(sizeof(struct Node));

	head-> data = 7;
	head-> link = second;

	second-> data=8;
	second->link=third;

	third-> data=69;
	third->link = fourth;

	fourth-> data=70;
	fourth->link = NULL;
	
	printf("Linked list before insertion\n");
	linklistTraversal(head);
	//head = insertAtFirst(head,72);
	//head = insertAtIndex(head,12,2);
	//head = insertAtEnd(head,12);
	//head=deleteAtFirst(head);
	head=deleteAtEnd(head);
	printf("\nLinked List after insertion\n");
	linklistTraversal(head);
	return 0;
}