// code almost similar to BFS
// just Dijkstra logic implemented



#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[105];

int distance_array[105];

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});                                   // mamually setting the destination as '0'
    distance_array[src] = 0;

    

    while (!q.empty())
    {
        pair<int, int> par = q.front();                                 // step(i); ber kore ana; ekta pair ber kore ana hocche
        q.pop();

        int par_node = par.first;
        int par_dis = par.second;


        // step(ii); oi node niye kaj (print the 'par')



        for (auto child : adj_list[par_node])                           // step(iii); children push
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < distance_array[child_node])                   // path relaxation condition; check v-7.6
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

            adj_list[a].push_back({b, w});                          // pushing pair in vector
            adj_list[b].push_back({a, w});
        }


//      memset(distance_array, INT_MAX, sizeof(distance_array));                          // initialize all the index as INT_MAX; but memset cant handle INT_MAX;
        for (int i = 0; i < n; i++)                                                       // manually initialize
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
