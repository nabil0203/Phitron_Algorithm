// clean code


#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int fibo(int a)
{
    if (a == 0 || a == 1)
    {
        return a;
    }

    if (dp[a] != -1)
    {
        return dp[a];
    }

    dp[a] = fibo(a - 1) + fibo(a - 2);

    return dp[a];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int a;
    cin >> a;

    cout << fibo(a);

    return 0;
}