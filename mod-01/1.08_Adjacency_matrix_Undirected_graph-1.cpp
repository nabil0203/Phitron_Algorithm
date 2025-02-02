#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;                                            // node and edge
    cin >> n >> e;
    int adj_mat [n][n];                                  // taking 2D array as matrix  

    /*
    for (int i = 0; i < n; i++)                         // making all the value of the matrix'0'
    {                                                   // can't do "int adj_mat [n][n] = {0}" bcz its a 2D Array
        for (int j = 0; j < n; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    */

    memset(adj_mat,0,sizeof(adj_mat));                  // shortcut of the nested loop; (kar memory set korbo, kon value set korbo, koto gula rakhbo)



    for (int i = 0; i < n; i++)                           // making Main Diagonal '1'; (B-227)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }    



    while (e--)                                          // number of edge is the number of connection
    {
        int a, b;                                        // for each connection
        cin >> a >> b;

        adj_mat[a][b] = 1;                               // making the connection both way '1'; bcz Undirected graph (B-226)
        adj_mat[b][a] = 1;
    }
    

    for (int i = 0; i < n; i++)                          // printing
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}