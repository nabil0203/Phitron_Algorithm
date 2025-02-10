#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[100];

int parent[105];                            // parent track er jonne alada array

bool cycle;

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        // ber kore ana
        int par = q.front();
        q.pop();



        // kaj kora



        // child push kora
        for (int child : adj_list[par])
        {
            if (vis[child] && parent[par] != child)                         // jodi child na hoy
            {
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;                                            // ke kar parent oita set kora hocche each time
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

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;                                       // starting ee kono cycle nai; tai BFS er age false

    for (int i = 0; i < n; i++)                           // disconneted graph er jonne sb Node e jeye check korte hobe Visited array false kina; false holei BFS
    {
        if (vis[i] == false)
            BFS(i);
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
6 5
0 1
1 2
2 3
3 0
4 5

Ouput-1:
Cycle Detected




Input-2:
6 4
0 1
1 2
2 3
4 5

output-2:
No Cycle




*/