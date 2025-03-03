// memoization is a technique to optimise the regular recursion
// memoization means "Save kore rakha"
// save koratai dp
// Complexity O(N)



#include <bits/stdc++.h>
using namespace std;


int dp[1005];            // took an array the save the value;
                         


int fibo(int a)
{
    if (a == 0 || a == 1)
    {
        return a;
    }

    if(dp[a] != -1)             // checking if it's already updated or not
    {
        return dp[a];
    }

    dp[a] = fibo(a - 1) + fibo(a - 2);          // dp array, index 2 er value = fibo of 2
                                                // dp array. index 3 er value = fibo of 3

    return dp[a];
}

int main()
{
    memset(dp,-1,sizeof(dp));

    int a;
    cin >> a;

    cout << fibo(a);

    return 0;
}