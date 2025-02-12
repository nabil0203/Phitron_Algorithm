// fresh code



#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];

int distance_array[105];

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    distance_array[src] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_node = par.first;
        int par_dis = par.second;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < distance_array[child_node])
            {
                distance_array[child_node] = par_dis + child_dis;
                q.push({child_node, distance_array[child_node]});
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
        int a, b, w;
        cin >> a >> b >> w;

        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }

    for (int i = 0; i < n; i++)
    {
        distance_array[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << distance_array[i] << endl;
    }

    return 0;
}