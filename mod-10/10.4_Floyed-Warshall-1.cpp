#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];



    for (int i = 0; i < n; i++)                           // setting the index value of adj_mat 2D matrix
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;                             // all main diagonal '0'
            }
            else
                adj_mat[i][j] = INT_MAX;                      // other index is MAX
        }
    }



    
    // input
    while (e--)
    {
        int a, b, c;                     // a,b->edge; c-> weight of edge
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
//      adj_mat[b][a] = c;                  // undirected
    }




    // floyd Warshall stars here
    // see the inner 2 loops first

    for (int k = 0; k < n; k++)                         // middle node
    {
        for (int i = 0; i < n; i++)                     // source
        {
            for (int j = 0; j < n; j++)                 // destination
            {

                if (adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX && (adj_mat[i][k] + adj_mat[k][j]   <   adj_mat[i][j]))                      // checking INT_MAX in both   &&   (source,des er majhe arekta node rekhe distance   <   source, des er direct distance)
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
                    cout << "INF ";                     // for better look in output
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