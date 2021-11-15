//This is a C++ program of Rod Cutting Problem In a Bottom Up Approach.
#include<bits/stdc++.h>

using namespace std;

float max(float a, float b) { return (a > b)? a : b;}

float cutRod(float p[],int n,float r[]){
    if(r[n] >= 0){ return r[n]; }
    float q;
    if(n == 0){ q = 0; }
    else{
        q = FLT_MIN;
        for(int i=0;i<n;i++){
            q = max(q,p[i] + cutRod(p,n-i-1,r));
        }
    }
    r[n] = q;
    return q;
}


int main()
{
	int n,n1;
	cout<<"Enter Length of Rod :";
	cin>>n;
    cout<<"Enter value of x :";
    cin>>n1;
    n = n * n1;
    float arr[n];
    float r[n+1];
    for(int i = 0;i<n+1;i++)
    r[i] = INT_MIN;
        
	cout<<"\nEnter Price of lengths :";
    for(int i = 0 ; i < n ; i++)
    cin>>arr[i];
    
	cout<<"\nMaximum Price Value is :"<<cutRod(arr,n,r);
    getchar();
    return 0;
}  
