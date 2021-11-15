#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

//this is a implementation of priority queue using max-heap made
//using binary heap

int menu(void);//Function to print menu()
void array_input(int *,int);
void array_output(int *,int);
//max-heap functions
int key_index(int,char *);
void build_max_heap(int *,int);
void max_heapify(int *,int,int);
void swap(int *,int *);
//priority queue functions
int heap_extract_maximum(int *,int *);
void increase_key(int *,int);
void heap_increase_key(int *,int,int);
int heap_maximum(int *);
void heap_insert(int *,int *,int);

int main()
{
	int n;
	printf("\nEnter the size of the array : ");
	scanf(" %d",&n);
	int *array=(int *)malloc(sizeof(int)*n);
	array_input(array,n);
	int heap_size=n;
	build_max_heap(array,heap_size);
	while(1)
	{
		switch(menu())
		{
			case 1: printf("\nThe key %d has been succesfully extracted...\n\n",heap_extract_maximum(array,&heap_size));
					break;
			case 2: heap_insert(array,&heap_size,n);
					break;
			case 3: increase_key(array,heap_size);
					break;
			case 4: printf("The maximum key is %d\n\n",heap_maximum(array));
					break;
			case 5: printf("The heap is : ");
					array_output(array,heap_size);
					break;
			case 6: printf("The array is : ");
					array_output(array,n);
					break;
			case 7: free(array);
					printf("Thank you for using my program...\n\n");
					exit(0);
		}
	}
	free(array);
	return 0;
}

void heap_insert(int *array,int *heap_size,int n)
{
	if((*heap_size)==n)
	{
		printf("\nHEAP OVERFLOW...\n");
	}
	else
	{
		(*heap_size)+=1;
		printf("\nEnter the new key : ");
		int key;
		scanf(" %d",&key);
		*(array+(*heap_size-1))=INT_MIN;
		heap_increase_key(array,key,(*heap_size)-1);
	}
	return;
}

int heap_maximum(int *array)
{
	return (*(array+0));
}

void increase_key(int *array,int n)
{
	int i,key,key_index,new_key;
	printf("\nEnter the key whose value you want to increase : ");
	scanf(" %d",&key);
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(key==*(array+i))
		{
			key_index=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nInvalid Key...\n");
		increase_key(array,n);
	}
	else
	{
		printf("\nEnter the new value of the key : ");
		scanf(" %d",&new_key);
		heap_increase_key(array,new_key,key_index);
	}
	return;
}

void heap_increase_key(int *array,int new_key,int i)
{
	*(array+i)=new_key;
	int parent_index=key_index(i,"parent");
	if(i>0 && *(array+i)>*(array+parent_index))  //NOTE --> 
	{
		swap(array+i,array+parent_index);
		i=key_index(i,"parent");
		parent_index=i;
	}
	return;
}

int heap_extract_maximum(int *array,int *heap_size)
{
	swap(array+0,array+(*heap_size)-1);
	(*heap_size)-=1;
	max_heapify(array,0,*heap_size);
	return *(array+*(heap_size));
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
	printf("1. Press 1 to extract maximum element...\n");
	printf("2. Press 2 to insert into the heap ...\n");
	printf("3. Press 3 to increase a key ...\n");
	printf("4. Press 4 to display maximum key ...\n");
	printf("5. Press 5 to display heap...\n");
	printf("6. Press 6 to display array...\n");
	printf("7. Press 7 to exit the program...\n\n");
	printf("Your Choice : ");
	scanf(" %d",&choice);
	printf("\n\n");
	return choice;
}
