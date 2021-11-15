#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
long long karatsuba(long long x , long long y){
  if(x<10||y<10)
  return x*y;
  int len = min(log10(x)+1,log10(y)+1);
  int m = floor(len/2);
  long long xl=floor(x/pow(10,m));
  long long xr=x%(int)(pow(10,m));
  long long yl=floor(y/pow(10,m));
  long long yr=y%(int)(pow(10,m));
  long long p1 = karatsuba(xl,yl);
  long long p2 = karatsuba(xr,yr);
  long long pr =karatsuba(xl+xr,yl+yr)-p1-p2;
  return (long long)(p1*(pow(10,len))+(pr)*(pow(10,m))+p2);

}

int main(){
    cout<<"Enter two numbers: ";
    long long x,y;
    cin>>x>>y;
    cout<<karatsuba(x,y)<<endl;
}