// DP used
// Memoization used to optimised code
// O(N W)
// N = number of items; W = max weight




#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];

int dp[1005][1005];                               // dp array for memoization; 2D used bcz we need work with both weight and price/value


int knapsack(int i, int max_weight)
{

    if(i < 0 || max_weight <= 0)                // base case
    {
        return 0;
    }

    

    // value already save ase kina
    if(dp[i][max_weight] != -1)
    {
        return dp[i][max_weight];                                           // already calcualted; memoization
    }




    if (weight[i] <= max_weight)
    {
        // 2 options
        // i) bag ee rakhbo, ii) bag ee rakhbo na

        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, max_weight);

        dp[i][max_weight] =  max(op1, op2);                                 // memoization; saving the value for check

        return dp[i][max_weight];

    }


    else
    {
        // 1 option
        // i) bag ee rakhbo na

        dp[i][max_weight] = knapsack(i - 1, max_weight);                      // memoization; saving the value for check
        return dp[i][max_weight];

    }

}



int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int max_weight;
    cin >> max_weight;




    for (int i = 0; i <= n; i++)                     // initilizing dp array as -1
    {
        for (int j = 0; j <= max_weight; j++)
        {
            dp[i][j] = -1;
        }
    }
    




    cout << knapsack(n - 1, max_weight);

    return 0;
}







/*

intput:
4                              // koyta item
10 4 7 5                      // value/price of the item
4 3 2 5                       // weight of the item
8                             // max weight capacity

output:
17


*/