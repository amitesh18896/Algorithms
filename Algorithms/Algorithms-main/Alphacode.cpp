#include <iostream>
#include <map>
using namespace std;

map<string, int> dataMap;

int countCombinations(string str)
{
    if (str.size() == 1)
    {
        if (str[0] == '0')
            return 0;
        else
            return 1;
    }
    if (str.size() == 2)
    {
        int first = str[0] - '0';
        int second = str[1] - '0';
        int val = first * 10 + second;
        if (first != 0 && val <= 26)
            return 2;
        else
            return 1;
    }
    if (dataMap[str] != 0)
    {
        return dataMap[str];
    }
    int first = str[0] - '0';
    int second = str[1] - '0';
    int val = first * 10 + second;
    if (val == 10 || val == 20)
    {
        str.erase(str.begin());
        str.erase(str.begin());
        return countCombinations(str);
    }
    if (val > 26)
    {
        str.erase(str.begin());
        return countCombinations(str);
    }
    str.erase(str.begin());
    int count = countCombinations(str);
    str.erase(str.begin());
    count += countCombinations(str);
    return count;
}

int main()
{
    while (1)
    {
        string str;
        getline(cin, str);
        if (str[0] == '0')
            break;
        cout << countCombinations(str) << '\n';
    }
    return 0;
}
