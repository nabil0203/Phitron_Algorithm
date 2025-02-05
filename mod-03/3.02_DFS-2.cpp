// fresh code



#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_array[1005];

void DFS(int src)
{
    cout << src << " ";
    visited_array[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited_array[child])
        {
            DFS(child);
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

    DFS(0);

    return 0;
}