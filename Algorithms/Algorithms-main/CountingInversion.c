#include<stdio.h>
#include<stdlib.h>

/*
	this is an approach to count number of inversions required such that a given
	sequence of numbers can be sorted.
	this method uses merge sort related implementation.

	time complexity --- O(n.logn)
	space complexity --- O(n)


*/


int mergeSort(int[] ,int);
int _aux(int[] ,int[], int, int);
int merge(int[], int[], int, int, int);

int main(){
	int n;
	printf("Enter length of array : ");
	scanf("%d",&n);
	printf("Enter elements of array : ");
	int *array = (int*)malloc(n* sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&array[i]);
	
	printf("Number of inversions required are %d\n",mergeSort(array,n));

}

int mergeSort(int* arr, int size){
	int* temp = (int*)calloc(size, sizeof(int));
	return _aux(arr, temp, 0, size-1);
}

// helping function to count inversions
int _aux(int* arr, int* temp, int low, int high){
	int inversion = 0;
	if(low < high){
		int mid = (low + high)/2;
		inversion += _aux(arr, temp, low, mid);
		inversion += _aux(arr, temp, mid+1, high);

		inversion += merge(arr, temp, low, mid+1, high);
		
	}
	return inversion;
}


int merge(int* arr, int* temp, int low, int mid, int high){
	int count = 0;
	int i = low;
	int j = mid;
	int k = low;
	while(i<= (mid-1) && j <= high){
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else{
			temp[k++] = arr[j++];
			count += (mid-i);
		}
	}
	// copy remaining elements of lower subarray to temp
	while(i <= (mid-1))
		temp[k++] = arr[i++];
	// copy remaining elements of higher subarray to temp
	while(j <= high)
		temp[k++] = arr[j++];
	// copy elements to original array
	for(i= low;i<= high;i++)
		arr[i] = temp[i];
	return count;
}