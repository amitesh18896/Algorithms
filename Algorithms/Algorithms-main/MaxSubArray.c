#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct Objects_t
{
    int start;
    int end;
    int sum;
};

typedef struct Objects_t *Object;

Object newObj()
{
    Object obj = (Object)calloc(1, sizeof(struct Objects_t));
    obj->start = 0;
    obj->end = 0;
    obj->sum = 0;
    return obj;
}

Object maximumCrossingSubArray(int *arr, Object obj, int mid)
{
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0, i;
    int low = obj->start, high = obj->end;
    int max_left, max_right;
    for(i=mid; i>=low; i--)
    {
        sum = sum + *(arr+i);
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(i = mid+1; i<=high; i++)
    {
        sum += *(arr+i);
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    Object cross;
    cross->start = max_left;
    cross->end = max_right;
    cross->sum = left_sum + right_sum;
    return cross;
}

Object maximumSubArray(int *arr, Object obj)
{
    int high = obj->end, low = obj->start;
    if(high == low)
    {
        obj->sum = *(arr + low);
        return obj;
    }
    int mid = (high + low)/2;
    printf("Here\t");
    obj->end = mid;
    Object left_obj = maximumSubArray(arr, obj);

    obj->end = high;
    obj->start = mid+1;
    Object right_obj = maximumSubArray(arr, obj);

    obj->start = low;
    Object cross_obj = maximumCrossingSubArray(arr, obj, mid);

    if(left_obj->sum >= right_obj->sum && left_obj->sum >= cross_obj->sum)
        return left_obj;
    else if(right_obj->sum >= left_obj->sum && right_obj->sum >= cross_obj->end)
        return right_obj;
    else
        return cross_obj;

}


int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int a[n], i;
    printf("Enter array elements: ");
    for(i=0; i<n; i++)
    {
    	scanf("%d", &a[i]);
	}
    Object obj = newObj();
    obj->end = n-1;
    obj = maximumSubArray(a, obj);
    printf("\nStart index: %d\nEnd index: %d\nSum : %d\n", obj->start, obj->end, obj->sum);

    return 0;
}

