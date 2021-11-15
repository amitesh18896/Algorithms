#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool *arr = new bool[n];
    for (int i = 3; i < n; i += 2)
    {
        arr[i] = true;
    }
    for (int i = 3; i * i < n; i += 2)
    {
        if (arr[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                arr[j] = false;
            }
        }
    }
    for (int i = 3; i < n; i += 2)
    {
        if (arr[i])
            cout << i << " ";
    }

    return 0;
}
