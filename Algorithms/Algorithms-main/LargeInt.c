#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

char *Addition(char *a, char *b)
{
    int sum=0, i=0, j=0, k=0, carry=0, x, y;
    int n = max(strlen(a), strlen(b));
    char *res = (char*)calloc(n, sizeof(char));
    //printf("a: %s\t b: %s\n", a, b);
    while(i<strlen(a) || i<strlen(b))
    {
        sum = 0;
        if(i<strlen(a))
            x = a[i] - '0';
        else
            x = 0;

        if(i<strlen(b))
            y = b[i] - '0';
        else
            y = 0;

        sum = x + y + carry;
        //printf("sum = %d\n",sum);
        if(sum/10 > 0)
        {
            res[k] = sum%10 + '0';
            carry = 1;
        }
        else
        {
            res[k] = sum + '0';
            carry = 0;
        }
        k++;
        i++;
    }
    res[k+1] = carry + '0';
    return strrev(res);
}

int main()
{
    char a[50], b[50], *a_rev, *b_rev, *sum;
    printf("Enter the first number: ");
    scanf("%s", a);
    printf("Enter the second number: ");
    scanf("%s", b);

    a_rev = strrev(a);
    b_rev = strrev(b);
    sum = Addition(a_rev, b_rev);

    printf("Result: %s\n", sum);

    return 0;
}

