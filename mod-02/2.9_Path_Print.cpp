// almost same as the Single Source Shortest Distance(2.8)
// the modifications are commneted




#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

bool visited_array[1005];

int level[1005];             

int parent[1005];                            // taking an Array to track the parent





void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited_array[src] = true;

    level[src] = 0;

//  parent[src] = -1;                        // source node doesn't have any parent; Therefore it's '-1'; But we dont need to this bcz in the Main Function, full Parent array has already been '-1'


    while (!q.empty())
    {
        int par = q.front();
        q.pop();

//      cout << par << " ";                                           // Don't need to print

        for (int child : adj_list[par])
        {
            if (visited_array[child] == false)
            {
                q.push(child);

                visited_array[child] = true;

                level[child] = level[par] + 1;

                parent[child] = par;                                         // parent of child = par
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

    memset(level, -1, sizeof(level));

    memset(parent, -1, sizeof(parent));                                     // initializing all the Parent as '-1'

    int src, destination;
    cin >> src >> destination;

    bfs(src);                                          // function call


    // for (int i = 0; i < n; i++)                                      // checking the parent of each node
    // {
    //     cout << i << " parent-> " << parent[i] << endl;
    // }



    vector<int> path;                                                  // vector used to Reverse the path; Bcz we are getting the path Reversely at the beginning
    
    int node = destination;                                           // Stars form Destination

    while (node!= -1)                                                 // Sourece node er Parent porjonto jabo; Source node Parent = -1
    {
        path.push_back(node);                                          // Node ke Vector ee push kore rakha hochhe 
        node = parent[node];                                           // then protibar Node ke tar Parent node ee niye jacchi
    }

    reverse(path.begin(),path.end());                                // reversing that vector
    for(int x : path)
    {
        cout << x << " ";                                            // printing the path
    }



    return 0;
}






/*
Input-1:
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

Ouput-1:
0 1 3 5 6



Input-2:
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

Ouput-2:
0 1 4 6

*/
