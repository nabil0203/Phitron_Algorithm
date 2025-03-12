// https://www.hackerrank.com/contests/phitron-problem-solvers-club-mock-contest/challenges/love-sum

#include <bits/stdc++.h>
using namespace std;

// int dp[1005];
vector<int> dp(1005,-1);

bool guess(long long int start, long long int des)
{
    if (start == des)
    {
        return true;
    }

    if (start > des)
    {
        return false;
    }

    // memoization
    if (dp[start] != -1)
    {
        return dp[start];
    }

    dp[start] = guess(start + 3, des) || guess(start + 4, des);

    return dp[start];
}

int main()
{
    // memset(dp, -1, sizeof(dp));
    // for(int i = 0; i<1005; i++)
    // {
    //     dp[i] = -1;
    // }

    long long int t;
    cin >> t;

    bool guessed = guess(0, t);

    if (guessed)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}