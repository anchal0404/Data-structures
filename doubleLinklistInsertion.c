#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata);
int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata);
int dl_delete_element(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
	//Allocating the memory for new node
	Dlist *new = malloc(sizeof (Dlist));

	// If the node is not created the returning failure
	if (!new)
	{
		return FAILURE;
	}
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	// If the list is empty then inserting the node as first node
	if (!*head && !*tail)
	{	
		*head = *tail = new;
		return SUCCESS;
	}
	new -> prev = *tail;
	(*tail) -> next = new;
	*tail = new;
	return SUCCESS;
}


int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{

}

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
	if(*head==NULL)
		return LIST_EMPTY;

	Dlist* temp=*head;
	while(temp!=NULL)
	{
		if(temp->data!=gdata)
			temp=temp->next;
		else
		{
			Dlist* new=(Dlist*)malloc(sizeof(Dlist));

			if(new==NULL)
				return FAILURE;

			new->data=ndata;
			new->prev=NULL;
			new->next=NULL;

			new->prev=temp;
			new->next=temp->next;
			if(temp!=*tail)
				temp->next->prev=new;
			else
				*tail=new;
			temp ->next=new;
		}
		return SUCCESS;
	}
	return DATA_NOT_FOUND;
}


int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	

}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}
int main()
{
	int option, data, gdata, ret;


	Dlist *head = NULL; /* initialize the header to NULL */
	Dlist *tail = NULL; /* initialize the tail to NULL */

	printf("1. Insert first\n2. Insert before\n3. Insert after\n4. Delete element\n5. Print list\n6. Exit\nEnter your choice : ");
	while(1)
	{

		/*ask user options*/
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				/* To insert the element at last */
				printf("Enter the data you have to insert : ");
				scanf("%d", &data);

				/* If the return value is 0 link sucess else not success */
				if (dl_insert_last(&head, &tail, data) == -1)
				{
					printf("INFO : Insert last Failure\n");
				}
				break;
			case 2:
				/* To insert the element before a number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata); /* Scaning the number */
				printf("Enter the number you have insert before %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data);

				/* If the link is Success it retuns 0 else it returns -1 */
				if ((ret = dl_insert_before(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert before Successfull\n" );
				}
				break;
			case 3:
				/* To insert the element after the number present in the list */
				printf("Enter the gdata : ");
				scanf("%d", &gdata);/* Scaning the existing number */
				printf("Enter the number you have to insert after %d : ", gdata);

				/* Scaning the new number to insert */
				scanf("%d", &data); 

				/* If the link is Success it will return 0 else it will return -1 */
				if ((ret = dl_insert_after(&head, &tail, gdata, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Insert after Successfull\n" );
				}
				break;
			case 4:
				/* To delete the element present in the list */
				printf("Enter the element you have to delete : ");
				scanf("%d", &data); /* Scaning the number to delete */

				/* If the delete is completed it will return 0 else it will return -1 */
				if ((ret = dl_delete_element(&head, &tail, data)) == LIST_EMPTY)
				{
					printf( "INFO : List Empty\n" );
				}
				else if (ret == DATA_NOT_FOUND)
				{
					printf( "INFO : Data not found\n" );
				}
				else 
				{
					printf( "INFO : Delete element Successfull\n" );
				}
				break;
			case 5:
				/* Calling the function to print the list */
				print_list(head);
				break;
			case 6:
				return SUCCESS;

			default: printf("Enter proper choice !!\n");
					 break;
		}

	}

	return SUCCESS;
}