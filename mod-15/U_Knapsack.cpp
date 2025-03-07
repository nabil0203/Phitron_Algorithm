// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U



#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];

int dp[1005][1005];

int knapsack(int i, int max_weight)
{
    // base case
    if (i < 0 || max_weight <= 0)
    {
        return 0;
    }

    // memoization
    if (dp[i][max_weight] != -1)
    {
        return dp[i][max_weight];
    }

    if (weight[i] <= max_weight)
    {

        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, max_weight);

        dp[i][max_weight] = max(op1, op2);

        return dp[i][max_weight];
    }

    else
    {

        dp[i][max_weight] = knapsack(i - 1, max_weight);
        return dp[i][max_weight];
    }
}

int main()
{
    int n, max_weight;
    cin >> n >> max_weight;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= max_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n - 1, max_weight);

    return 0;
}