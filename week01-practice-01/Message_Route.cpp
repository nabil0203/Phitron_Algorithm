// https://cses.fi/problemset/task/1667/



#include <bits/stdc++.h>
using namespace std;



vector<int> adj_list[100005];

bool visited_array[100005];

int level[100005];

int parent[100005];





void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited_array[src] = true;

    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (visited_array[child] == false)
            {
                q.push(child);

                visited_array[child] = true;

                level[child] = level[par] + 1;

                parent[child] = par;
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

    memset(parent, -1, sizeof(parent));

    int src = 1, destination = n;                               // change

    cin >> src >> destination;

    bfs(src);

    if (!visited_array[destination])                            // change
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    int node = destination;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}