#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu(void);//Function to print menu()
void array_input(int *,int);
void array_output(int *,int);
//max-heap functions
int key_index(int,char *);
void build_max_heap(int *,int);
void max_heapify(int *,int,int);
void swap(int *,int *);
//heap-sort function
void heap_sort(int *,int);

int main()
{
	int n;
	printf("\nEnter the size of the array : ");
	scanf(" %d",&n);
	int *array=(int *)malloc(sizeof(int)*n);
	array_input(array,n);
	build_max_heap(array,n);
	while(1)
	{
		switch(menu())
		{
			case 1: heap_sort(array,n);
					break;
			case 2: printf("The heap is : ");
					array_output(array,n);
					break;
			case 3: printf("The array is : ");
					array_output(array,n);
					break;
			case 4: free(array);
					printf("Thank you for using my program...\n\n");
					exit(0);
			default:printf("Invalid choice...\n\n");
					break;
		}
	}
	free(array);
	return 0;
}

void heap_sort(int *array,int n)
{
	int flag=0,i;
	for(i=0;i<n-1;i++)
	{
		if(*(array+i)>*(array+i+1))
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\nThe array is already sorted!!!\n");
	}
	else
	{
		for(i=n;i>0;i--)
		{
			swap(array+0,array+n-1);
			n-=1;
			max_heapify(array,0,n);
		}
		printf("The array is now sorted!!!\n\n");
	}
	return;
}

//max-heap functions
void build_max_heap(int *array,int n)
{
	int i;
	for(i=((int)(n/2)-1);i>=0;i--)
	{
		max_heapify(array,i,n);
	}
	return;
}

void max_heapify(int *array,int i,int n)
{
	int largest,left,right;
	left=key_index(i,"left");
	right=key_index(i,"right");
	if(left<n && *(array+i)<*(array+left))
	{
		largest=left;
	}
	else
	{
		largest=i;
	}
	if(right<n && *(array+largest)<*(array+right))
	{
		largest=right;
	}
	if(largest!=i)
	{
		swap(array+largest,array+i);
		max_heapify(array,largest,n);
	}
	return;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int key_index(int i,char *str)
{
	i+=1;
	if(strcmp(str,"parent")==0)
	{
		return ((int)(i/2)-1);
	}
	else if(strcmp(str,"left")==0)
	{
		return ((2*i)-1);
	}
	else
	{
		return (2*i);
	}
}

void array_input(int *array,int n)
{
	int i;
	printf("\nThe program will now ask for array elements...\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the no. %d element : ",i+1);
		scanf(" %d",array+i);
	}
	printf("\n");
	return;
}

void array_output(int *array,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(array+i));
	}
	printf("\n\n");
	return;
}

int menu(void)
{
	printf("============MENU============\n\n");
	int choice;
	printf("1. Press 1 to sort the array...\n");
	printf("2. Press 2 to display heap...\n");
	printf("3. Press 3 to display array...\n");
	printf("4. Press 4 to exit the program...\n\n");
	printf("Your Choice : ");
	scanf(" %d",&choice);
	printf("\n");
	return choice;
}
