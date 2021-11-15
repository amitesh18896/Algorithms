# include <stdio.h>
# include <stdlib.h>


static void marge(int *a,int *b, int low, int high, int highend){
                  int le = high -1, l = low, h = high + 1;
                  int k = low;
                 // int b[5]; //= (int *)malloc(10 * sizeof(int));
                  while(l < le && h < highend){
                    if(a[l] > a[h]){
                       b[k++] = a[l++];
                    }
                    else{
                        b[k++] = a[h++];
                    }
                  }
                    while(l <= le){
                        b[k++] = a[l++];

                    }
                    while(h <= highend){
                        b[k++] = a[h++];

                    }
                    for(int i = low; i <= highend; i++){
                        a[i] = b[i];//printf("FGVBN");
                    }
            }


static void margesortHelper(int *a, int *temp, int low, int high){
                if(low < high){
                    int mid = (low + high)/2;
                    margesortHelper(a,temp, low, mid);
                    margesortHelper(a, temp, mid + 1, high);
                    marge(a, temp, low, mid +1 , high);
                }
}


static void margesort(int *p, int n){
        int *temp = (int *)malloc(n*sizeof(int));
        margesortHelper(p,temp,0,n-1);
        free(temp);
}



void main(){
       int n;
       printf("Enter array size : ");
       scanf("%d",&n);
       int *a = (int *)malloc(n*sizeof(int));
       printf("Enter your array : ");
       for( int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        }
        margesort(a,n);
        printf(" your array : ");
       for( int i = 0; i < n; i++){
        printf("%d ",a[i]);
        }

}
