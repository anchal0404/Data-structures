#include <stdio.h>
#include<stdlib.h>

#define FAILURE -1
#define SUCCESS 0
#define Q_FULL -1
typedef struct {
	unsigned int capacity;
	int front,rear;
	int* items;
}Queue_t;

int creat_Queue(Queue_t* q,int size)
{
	q->items = malloc(sizeof(int)*size);
	if(q->items == NULL)
		return FAILURE;
	q->rear = -1;
	q->front = -1;
	q->capacity = size;
	return SUCCESS;
}

int IsQueueFull(Queue_t *q)
{
	if(q->rear==(q->capacity)-1)
		return 1;
	else
		return 0;
}

int IsQueueEmpty(Queue_t *q)
{
	if(q->rear==-1)
		return 1;
	else
		return 0;
}

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
	if(IsQueueFull)
		return Q_FULL;
	if(q->front==-1)
		q->front+=1;
	++(q->rear);
	q->items[q->rear]=data;
	return SUCCESS;
}



/* Function to print the Queue */
int print_queue(Queue_t q)
{

	/* Checking the queue is empty or not */
	if (IsQueueEmpty(&q) == SUCCESS)
	{
		printf("INFO : Queue is empty\n");
		return FAILURE;
	}

	printf("Front -> ");
	do
	{
		printf("%d ", q.items[q.front]);
		q.front = (q.front + 1) % q.capacity;
		/* Printing the queue till it will reaches end */	
	}while (--(q.front));

	printf("<- Rear\n");

	/* Returning SUCCESS */
	return SUCCESS;
}

int main(int argc, char const *argv[])
{
	Queue_t q;
	int size;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);

	if(creat_Queue(&q,size)==FAILURE)
	{
		printf("INFO : Queue not created\n");
		return FAILURE;
	}
	
	char ch;
	int choice, data;
	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");
	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			/*case 2:
				//Function to dequeueue the queue 
				if (dequeue(&q) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;*/
			case 3:
				/* Function to print the queue */
				print_queue(q);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}
	