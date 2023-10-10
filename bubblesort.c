#define SUCCESS 0
    
#include<stdio.h>

typedef int data_t;

data_t bubble(data_t *arr, data_t size);

int main()
{
	int i, limit, option;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	data_t arr[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &arr[i]);
	}
	printf("Hello");

	/* Calling the function to bubble sort */
	bubble(arr, limit);
	
	printf("Hello");
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
		
	return 0;
}




data_t bubble(data_t *arr, int size )
{
	
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1 ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	return SUCCESS;
}