#include<stdio.h>
#include<stdlib.h>

//Assumption - data and key are same
struct node{
	int data;
	struct node *next;
};

typedef struct node node;

int hash_function(int,int);
void insert(node ***,int);
void chaining(node ***,node *,int);
void delete(node ***,int);
void search(node ***,int);
void memory_alloc(node ***,int m);
void menu(int *);
void print_keys(node ***,int);

int main()
{
	int m,choice=0;
	printf("\nEnter approximate number of keys : ");
	scanf(" %d",&m);
	node **hash_table;
	memory_alloc(&hash_table,m);
	while(choice!=5)
	{
		menu(&choice);
		switch(choice)
		{
			case 1: insert(&hash_table,m);
					break;
			case 2: search(&hash_table,m);
					break;
			case 3: delete(&hash_table,m);
					break;
			case 4: print_keys(&hash_table,m);
					break;
			case 5: printf("Thank you for using my Program!!!\n");
					printf("Developed by Ankit Kumar\n\n");
					break;
			default: printf("Invalid Choice!!!");
					break;
		}
	}
	return 0;
}

void memory_alloc(node ***hash_table,int m)
{	
	(*hash_table)=(node **)malloc(sizeof(node *)*m);
	if((*hash_table)==NULL)
	{
		printf("\n\nCANNOT RUN, MEMORY FULL!!!\n");
		printf("Exiting!!!\n\n");
		exit(1);
	}
	else
	{
		int i;
		for(i=0;i<m;i++)
		{
			*((*hash_table)+i)=NULL;
		}
		return;
	}
}

int hash_function(int key,int m)
{
	return key%m;
}

void insert(node ***hash_table,int m)
{
	printf("\nINSERTING NODE...\n\n");
	node *temp=(node *)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("CANNOT INSERT, MEMORY FULL!!!\n\n");
		return;
	}
	else
	{
		printf("Please enter the data : ");
		scanf(" %d",&(temp->data));
		chaining(hash_table,temp,m);
		printf("\nKEY SUCCESSFULLY INSERTED!!!\n");
		return;
	}
}

void chaining(node ***hash_table,node *key,int m)
{
	int index=hash_function(key->data,m);
	if(*((*hash_table)+index)==NULL)
	{
		*((*hash_table)+index)=key;
		key->next=NULL;
	}
	else
	{
		key->next=*((*hash_table)+index);
		*((*hash_table)+index)=key;
	}
	return;
}

void delete(node ***hash_table,int m)
{
	int key;
	printf("Enter the key which you want to delete : ");
	scanf(" %d",&key);
	printf("\nDELETING THE GIVEN KEY...\n\n");
	int index=hash_function(key,m);
	node *prev,*ptr=*((*hash_table)+index);
	if(ptr->data==key)
	{
		node *temp=ptr;
		ptr=ptr->next;
		free(temp);
		printf("\nKEY SUCCESSFULLY DELETED!!!\n");
		return;
	}
	else
	{
		prev=ptr;
		ptr=ptr->next;
		while(ptr->data!=key)
		{
			ptr=ptr->next;
			prev=prev->next;
			if(ptr==NULL)
			{
				printf("\n\nThe given key does not exist!!!\n\n");
				return;
			}
		}
		node *temp=ptr;
		if(ptr->next==NULL)
		{
			prev->next=NULL;
			free(ptr);
			printf("\nKEY SUCCESSFULLY DELETED!!!\n");
			return;
		}
		else
		{
			prev->next=ptr->next;
			free(ptr);
			printf("\nKEY SUCCESSFULLY DELETED!!!\n");
			return;
		}
	}
}

void search(node ***hash_table,int m)
{
	int key;
	printf("Enter the key which you want to search : ");
	scanf(" %d",&key);
	printf("\n\nSEARCHING FOR THE KEY...\n\n");
	int index=hash_function(key,m);
	node *temp=*((*hash_table)+index);
	while(temp->data!=key && temp!=NULL)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("The given key does not exist!!!\n");
	}
	else
	{
		printf("The given key exists!!!\n");
	}
	return;
}

void menu(int *choice)
{
	printf("\n\n********************MENU********************\n");
	printf("The Serial number corresponds to the option\n\n");
	printf("1. Do you want to insert any key ?\n");
	printf("2. Do you want to search any key ?\n");
	printf("3. Do you want to delete any key ?\n");
	printf("4. Do you want to print all keys ?\n");
	printf("5. Do you want to exit the program ?\n\n");
	printf("Your Choice : ");
	scanf(" %d",choice);
	printf("\n");
	return;
}

void print_keys(node ***hash_table,int m)
{
	int i;
	node *temp;
	printf("PRINTING KEYS...\n\n");
	for(i=0;i<m;i++)
	{
		temp=*((*hash_table)+i);
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n\nKEYS SUCCESSFULLY PRINTED!!!\n\n");
	return;
}

//Debugging
//printf("\n\nCHECK!!!!!!!!!\n\n");
