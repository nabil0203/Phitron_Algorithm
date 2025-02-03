#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

bool visited_array[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    
    visited_array[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

//      cout << par << " ";                                       // we don't need to print in this problem

        for (int child : adj_list[par])
        {
            if (visited_array[child] == false)
            {
                q.push(child);
                visited_array[child] = true;
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


    int src, destination;
    cin >> src >> destination;                            // check a node can be visited from another node, SO two extra node needed as source and destination



    bfs(src);                                     // funtion calling




    if(visited_array[destination])                      // checking if the Destination is can be visited or not
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}





/*
input-1:
7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5
0
4

Output-1:
YES



input-2:
7 5
0 1
1 3
3 2
4 6
3 5
0
4

Output-2:
NO

*/
