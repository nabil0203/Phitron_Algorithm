// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/shortest-distance-2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    long long adj_mat[n + 5][n + 5];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
                adj_mat[i][j] = LONG_MAX;
        }
    }

    // input
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

   
    // floyd Warshall stars here

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (adj_mat[i][k] != LONG_MAX && adj_mat[k][j] != LONG_MAX && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }



    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        if (adj_mat[x][y] == LONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[x][y] << endl;
    }
    return 0;
}