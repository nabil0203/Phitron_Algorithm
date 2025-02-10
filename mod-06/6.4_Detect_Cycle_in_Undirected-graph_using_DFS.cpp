// same logic as BFS
// just DFS is implemented




#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[100];

int parent[105];

bool cycle;

void DFS(int src)
{
    vis[src] = true;


        for (int child : adj_list[src])
        {
            if (vis[child] && parent[src] != child)                         // jodi child na hoy
            {
                cycle = true;
            }

            if (!vis[child])
            {
                parent[child] = src;                                     // age parent set hobe
                DFS(child);                                              // then recursion call
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

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;                                       // starting ee kono cycle nai; tai DFS er age false

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            DFS(i);                                     // DFS called
    }

    if (cycle)
    {
        cout << "Cycle Detected";
    }
    else
        cout << "No Cycle";

    return 0;
}





/*

Input-1:
5 4
0 1
2 3
3 4
4 2

Ouput-1:
Cycle Detected


Input-2
6 4
0 1
1 2
2 3
4 5

Ouput-2:
No Cycle


*/