// almost same as the BFS
// the modifications are commneted




#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

bool visited_array[1005];

int level[1005];                                      // taking an Array to track the Level





void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited_array[src] = true;

    level[src] = 0;                                     // Source er level '0'


    while (!q.empty())
    {
        int par = q.front();
        q.pop();

//      cout << par << " ";                                              // Don't need to print

        for (int child : adj_list[par])
        {
            if (visited_array[child] == false)
            {
                q.push(child);

                visited_array[child] = true;

                level[child] = level[par] + 1;                            // the child Level = parent level + 1
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
        adj_list[b].push_back(a);
    }

    memset(visited_array, false, sizeof(visited_array));

    memset(level, -1, sizeof(level));                               // initializing ALL the Level as '-1'


    int src, destination;
    cin >> src >> destination;

    bfs(src);


    // for (int i = 0; i < n; i++)                                  // checking the level of each node
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }
    

    cout << level[destination];                                    // shortest path = level of the destination


    return 0;
}






/*
Input-1:
7 8
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0
6

Ouput-1:
2




Input-2:
7 7
0 1
1 3
3 2
1 4
3 5
2 5
5 6
0
6

Ouput-2:
4



Input-3:
9 7
0 1
1 3
3 2
1 4
3 5
2 5
5 6
7 8
0
6

Ouput-3:
-1                                  // -1 means, oi node ee jaoai jay na

*/
