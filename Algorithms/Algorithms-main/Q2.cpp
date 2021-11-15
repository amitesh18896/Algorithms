#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int max(int a, int b)
{
    return ((a > b) ? a : b);
}
int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxcrosssum(int a[], int l, int m, int h)
{
    int sum = 0;
    int lsum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum += a[i];
        if (sum > lsum)
            lsum = sum;
    }
    sum = 0;
    int rsum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum += a[i];
        if (sum > rsum)
            rsum = sum;
    }
    return max(lsum + rsum, lsum, rsum);
}
int maxsubarray(int a[], int low, int high)
{
    if (low == high)
        return a[1];
    int mid = (low + high) / 2;
    return max(maxsubarray(a, low, mid), maxsubarray(a, mid + 1, high), maxcrosssum(a, low, mid, high));
}
int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxsum = maxsubarray(a, 0, n - 1);
    cout << "Maximum sum is : " << maxsum << "\n";
}