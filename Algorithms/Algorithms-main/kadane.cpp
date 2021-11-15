// C++ program to print largest contiguous array sum with time complexity of O(n). Also known as Kadane’s Algorithm

#include<bits/stdc++.h> 

using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
	int max = INT_MIN, max_temp = 0; 

	for (int i = 0; i < size; i++) 
	{ 
		max_temp = max_temp + a[i]; 
		if (max < max_temp) 
			max = max_temp; 

		if (max_temp < 0) 
			max_temp = 0; 
	} 
	return max; 
} 

int main() 
{ 
	int n;
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i ++)
	cin>>a[i];
	cout << "Maximum contiguous sum is : " << maxSubArraySum(a, n); 
	return 0; 
} 
