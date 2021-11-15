#include<stdio.h>

int power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    return n%2 == 0 ? power(x, n/2) * power(x,n/2) : x * power(x,(n-1)/2) * power(x,(n-1)/2);
}

int main () {
    int x = 5, n = 5;
    printf("%d^%d = %d\n", x, n, power(x, n));
    return 0;
}
