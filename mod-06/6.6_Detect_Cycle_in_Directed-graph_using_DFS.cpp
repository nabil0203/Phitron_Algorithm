// almost same as 6.4
// changes are commented




#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[100];

bool pathvis[105];

bool cycle;

void DFS(int src)
{
    vis[src] = true;
    pathvis[src] = true;                // making true everytime


        for (int child : adj_list[src])
        {
            if (vis[child] && pathvis[child]) // both have to be true
            {
                cycle = true;
            }

            if (!vis[child])
            {
                DFS(child);
            }
        }
    // retuning from here
    pathvis[src] = false;
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
//      adj_list[b].push_back(a);                       // bcz directed
    }

    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            DFS(i);
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
4 4
0 1
1 2
2 3
3 0

Ouput-1:
Cycle Detected




Input-2
4 4
0 1
1 2
2 3
0 3

Ouput-2:
No Cycle


*/