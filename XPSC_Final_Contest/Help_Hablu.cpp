// https://www.hackerrank.com/contests/phitron-problem-solvers-club-final-contest-batch-6/challenges/help-hablu-1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        long long dp[s1.size() + 5][s2.size() + 5];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= s1.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        cout << dp[s1.size()][s2.size()] << endl;
    }

    return 0;
}