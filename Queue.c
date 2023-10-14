#include<stdio.h>
#include<stdlib.h>
#ifndef SUCCESS
#define SUCCESS 1
#define FAILURE 0
#endif

typedef struct
{
	unsigned int capacity;
	int front, rear;
	int *items;
}Queue_t;

int isFULL(Queue_t* Q)
{
	if(Q->rear == Q->capacity - 1)
		return 1;
	return 0;
}

int isEmpty(Queue_t* Q)
{
	if(Q -> rear==-1)
		return 1;
	return 0;
}
int create_queue(Queue_t *Q,int size)
{
	Q->items = (int*)malloc(sizeof(int)*size);
	Q->capacity=size;
	Q->front=Q->rear=-1;
	return SUCCESS;
}

int enqueue(Queue_t* Q,int data)
{
	if(isFULL(Q))
		return FAILURE;
	else
		++Q->rear;
		Q->items[Q->rear]=data;
		return SUCCESS;
}

int dequeue(Queue_t* Q)
{
	int element;
	if(isEmpty(Q))
		return FAILURE;
	Q->front++;
	element = Q->items[Q->front];
	return element;
}


int print_queue(Queue_t *Q)
{
	if(isEmpty)
	{
		printf("INFO:Queue is empty\n");
	}
	else
	{
		printf("FRONT->");

		while(Q->front)
		{
			printf("%d ",Q->items[Q->front]);
			Q->front = Q->front + 1;
		}
		printf("<-REAR\n");
		return SUCCESS;
	}

}

int main(int argc, char const *argv[])
{
	Queue_t Q;
	int size,choice;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);

	create_queue(&Q,size);

	while(1)
	{
		printf("\nEnter your choice:\n");
		
		printf("1.Enqueue\n2.Dequeue\n3.Print queue\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				int data;
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&Q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(&Q);
				break;
			case 4:
				exit(1);
			default:
				printf("Invalid option.\n");

		}


	}
	

	
	return 0;
}