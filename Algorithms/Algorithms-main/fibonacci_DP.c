#include<stdio.h>

int fib(int n, int* f) {
    if(n == 0 || n == 1) {
        return n;
    } else if(f[n] != -1) {
        return f[n];
    } else {
        f[n] = fib(n-1, f) + fib(n-2, f);
        return f[n];
    }
}

int main() {
    int f[100], n;
    for(int i = 0; i < 100; i++) {
        f[i] = -1;
    }
    printf("Enter a number to calculate fibonacci : ");
    scanf("%d", &n);
    printf("Fibonacci of given number is : %d", fib(n,f));

}
