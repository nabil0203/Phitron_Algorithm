// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-or-not-1-1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    memset(adj_mat, 0, sizeof(adj_mat));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int src, destination;
        cin >> src >> destination;

        if (adj_mat[src][destination] == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}