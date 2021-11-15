//This is a C++ program to multiply Two polynomials Using Divide and Conquer.
#include <bits/stdc++.h>

using namespace std;

void compute(int start, int end, int A[], int B[], int C[]){

	if (end == start){
	    C[2*end] += A[end]*B[end];
	    return;
	}
	int mid = (end+start)/2 ;
	
	compute(start, mid, A, B, C); 
	
	compute(mid+1, end, A, B, C); 
	
	for(int i=start; i<=mid; i++){
	    for(int j=mid+1; j<=end; j++){
	        C[i+j] += A[i]*B[j] + A[j]*B[i];
	    }
	}
}

int main(){
    int degree;
    cout<<"Enter degree of the polynomial: ";
    cin>>degree;

    int n = degree;
    
    int a[n+1]  = {};
    cout<<"Enter coefficients of polynomial A in increasing order of power of x :";
    for(int i=0; i<n+1; i++)
        cin>>a[i];
    
    int b[n+1]  = {};
    cout<<"Enter coefficients of polynomial B in increasing order of power of x :";
    for(int i=0; i<n+1; i++)
        cin>>b[i];
    
    int AB [2*n + 1]    = {};
    
    compute(0, degree, a, b, AB);
    
     for (int i=0; i<2*n+1; i++) 
	{ 
		cout << AB[i]; 
		if (i != 0) 
			cout << "x^" << i ; 
		if (i != 2*n) 
		cout << " + "; 
	} 
        
    cout<<"\n";    
}

