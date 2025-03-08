// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-06/challenges/make-it-2

#include <bits/stdc++.h>
using namespace std;

int dp[100005];

bool makeIT(int start, int des)
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

    dp[start] = makeIT(start + 3, des) || makeIT(start * 2, des);

    return dp[start];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));

        int n;
        cin >> n;

        bool madeIT = makeIT(1, n);

        if (madeIT)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}