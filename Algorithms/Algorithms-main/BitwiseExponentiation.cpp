#include <iostream>
using namespace std;

long long expo(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        long long a, b;
        cin >> a >> b;
        long long res = expo(a, b);
        cout << res << '\n';
    }
    return 0;
}
