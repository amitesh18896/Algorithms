#include<stdio.h>
#include<stdlib.h>

void array_input(int *,int);
void merge_sort(int *,int,int);       //divide operations
void merge(int *,int *,int *,int,int,int);     //conquer and combine operation
void array_output(int *,int);

int main()
{
	int n;
	printf("\nENTER THE SIZE OF THE ARRAY : ");
	scanf(" %d",&n);
	int *array=(int *)malloc(sizeof(int)*n);
	array_input(array,n);
	int flag=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(*(array+i)>*(array+i+1))
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nTHE ARRAY IS ALREADY SORTED!!!\n");
		return 0;
	}
	array_output(array,n);
	merge_sort(array,0,n-1);
	array_output(array,n);
	printf("\n");
	free(array);
	return 0;
}

void merge_sort(int *array,int start,int end)
{
	printf("\nDEBUg ==> START --> %d and END --> %d\n",start,end);
	if(start==end)
	{
		return;
	}
	int mid=(start+end)/2;
	printf("\nDEBUg ==> START --> %d, MID -->%d and END --> %d\n",start,mid,end);
	int i,k;
	int *left_array=(int *)malloc(sizeof(int)*(mid-start+1));
	k=0;
	for(i=start;i<=mid;i++)
	{
		*(left_array+k)=*(array+i);
	}
	int *right_array=(int *)malloc(sizeof(int)*(end-mid));
	k=0;
	for(i=mid+1;i<=end;i++)
	{
		*(right_array+k)=*(array+i);
	}
	merge_sort(left_array,start,mid);
	merge_sort(right_array,mid+1,start);
	merge(array,left_array,right_array,start,mid,end);
	free(left_array);
	free(right_array);
	return;
}

void merge(int *array,int *left_array,int *right_array,int start,int mid,int end)
{
	int i,j,k;
	i=0,j=0;
	for(k=start;k<=end && i<=(mid-start+1) && j<=(end-mid);k++)
	{
		if(*(left_array+i)>*(right_array+j))
		{
			*(array+k)=*(left_array+i);
			i++;
		}
		else
		{
			*(array+k)=*(right_array+j);
			j++;
		}
	}
	//left-overs
	for(i=i;i<=(mid-start+1);i++,k++)
	{
		*(array+k)=*(left_array+i);
	}
	for(j=j;j<=(end-mid+1);j++,k++)
	{
		*(array+k)=*(right_array+j);
	}
	return;
}

void array_output(int *array,int n)
{
	int i;
	printf("\n\nTHE ARRAY IS ");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(array+i));
	}
	printf("\n\n");
	return;
}

void array_input(int *array,int n)
{
	printf("\n\nPLEASE INPUT ARRAY ELEMENTS...\n\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nINPUT THE %d ELEMENT : ",i+1);
		scanf(" %d",array+i);
	}
	return;
}
