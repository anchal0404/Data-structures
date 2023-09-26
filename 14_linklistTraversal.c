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

//Main Functio 
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
	linklistTraversal(head);
	return 0;
}