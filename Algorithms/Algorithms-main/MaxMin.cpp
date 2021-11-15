//This is a c++ program to calculate maximum and minimum in an array using Divide And Conquer.
#include<bits/stdc++.h>

using namespace std;

int *a;

void max_min(int i , int j , int &max , int &min)
{
	if(i==j)
	{
		if(max < a[i])
		max = a[i];
		
		if(min > a[i])
		min = a[i];
		
		return;
	}
	
	if(j - i == 1)
	{
		{
		if (a[i] < a[j])	
		{
			if (min > a[i])	 
			min = a[i];

			if (max < a[j])	
			max = a[j];
		}
		else
		{
			if (min > a[j])
			min = a[j];

			if (max < a[i])	 
			max = a[i];
		}
			return;
		}

	}
	else
	
	{
		int mid = (i + j)/2;
		max_min(i,mid,max,min);
		max_min(mid+1,j,max,min);
		
	}
}

int main()
{
	int n;
	cin>>n;
	a = (int *)malloc(n*sizeof(int));
	for(int i = 0 ; i < n ; i++)
	cin>>a[i];
	
	int max = INT_MIN,min = INT_MAX;
	
	max_min(0,n-1,max,min);
	
	cout<<"Max :"<<max<<"\nMin :"<<min;
	
}
