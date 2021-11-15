#include <iostream>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int findDistance(string str1, string str2, int m, int n)
{

    int matrix[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                matrix[i][j] = j;

            else if (j == 0)
                matrix[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];

            else
                matrix[i][j] = 1 + min(matrix[i][j - 1],
                                       matrix[i - 1][j],
                                       matrix[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    int test;
    cin >> test;
    for (int T = 0; T < test; T++)
    {
        string str1, str2;
        cin >> str1;
        cin >> str2;
        int d = findDistance(str1, str2, str1.length(), str2.length());
        cout << d << "\n";
    }
    return 0;
}
