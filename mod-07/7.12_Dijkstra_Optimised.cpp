// almost same as Dijkstra Naive
// priority queue used
// changes are commented



#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];

int distance_array[105];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;           // minimum priority queue insted of queue

    pq.push({0,src});                                                                          // distance pushed frist then source

    distance_array[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();                                                 // front changed to top
        pq.pop();

        int par_node = par.second;                                               // node pushed second
        int par_dis = par.first;                                                 // distance pushed first

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < distance_array[child_node])                           // path relaxaion
            {
                distance_array[child_node] = par_dis + child_dis;
                pq.push({distance_array[child_node], child_node});                              // name change & distance pushed frist then source
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





/*

input:
5 8
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

output:
0 -> 0
1 -> 6
2 -> 5
3 -> 4
4 -> 9


*/