#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];                                 // input of BFS as adjacency list; Decalred gobally to acces from any function

bool visited_array[1005];                                   // visted array; bool type




void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited_array[src] = true;                                                   // after each push, we are making that index in Visited_array TURE

    while (!q.empty())
    {
        int par = q.front();                                // step(i); ber kore ana; jake ber kore anteci oita 'par' ee rakha hocche
        q.pop();



        cout << par << " ";                                 // step(ii); oi node niye kaj (print the 'par')



        for (int child : adj_list[par])                      // step(iii); children push into Vector;
        {                                                           //'adj_list'-array er 'par' index ee jacchi; 'par'-index ee ekta vector ase; oi vector er ekta ekta value 'child' ee anci 
        
            if(visited_array[child] == false)                        // children already visited kina; false=not visited, so can push
            {
                q.push(child);
                visited_array[child] = true;                                           // after each push, we are making that index in Visited_array TURE
            }
            
        }
    }
}





int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);                     // undirected
    }


    memset(visited_array, false, sizeof(visited_array));                        // initially Full Visited array is False

    bfs(0);                                                          // calling BFS function; passing '0' as Source node

    return 0;
}




/*

input:
7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5

Ouput:
0 1 3 4 2 5 6

*/
