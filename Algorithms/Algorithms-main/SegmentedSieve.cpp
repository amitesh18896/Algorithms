#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

void simpleSieve(int n)
{
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
    primes.push_back(2);
    for (int i = 3; i < n; i += 2)
    {
        if (arr[i])
            primes.push_back(i);
    }
}

void segmentedSieve(int L, int R)
{
    if (L == 1)
        L++;

    int limit = floor(sqrt(R)) + 1;
    simpleSieve(limit);

    int n = R - L + 1;
    bool arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = true;
    }
    for (int i = 0; i < primes.size(); i++)
    {
        int base = floor(L / primes[i]) * primes[i];
        if (base < L)
        {
            base = base + primes[i];
        }
        if (base == primes[i])
        {
            base = base + primes[i];
        }

        for (int j = base; j <= R; j += primes[i])
        {
            arr[j - L] = false;
        }
    }
    for (int i = L; i <= R; i++)
    {
        if (arr[i - L])
        {
            cout << (i) << '\n';
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int a, b;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        segmentedSieve(a, b);
    }
    return 0;
}
