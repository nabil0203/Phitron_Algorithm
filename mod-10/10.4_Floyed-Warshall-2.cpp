// fresh code


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    // input
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
    }



    // floyd Warshall stars here
    // see the inner 2 loops first

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]))
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

Intput:
4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

Output:
0 3 5 8
INF 0 2 5
INF INF 0 4
INF INF INF 0


*/