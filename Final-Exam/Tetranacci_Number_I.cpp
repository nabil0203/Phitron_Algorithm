// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/tetranacci-number-a-easy-version

#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int tetra(int a)
{
    if (a == 0 || a == 1)
    {
        return a;
    }

    if (dp[a] != -1)
    {
        return dp[a];
    }

    dp[a] = tetra(a - 1) + tetra(a - 2) + tetra(a - 3) + tetra(a - 4);

    return dp[a];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int a;
    cin >> a;

    cout << tetra(a);

    return 0;
}