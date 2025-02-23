#include <bits/stdc++.h>
using namespace std;

class Edge                                  // class to access all the properties of each edge at a time
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};


int dis[1005];                  // distance array


int main()
{
    int n, e;
    cin >> n >> e;



    // edge list input

    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;                                          // a,b-> edge; c->weight/cost
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));                 // edge class er object ee protibar a, b, c er value push hocche
//      edge_list.push_back(Edge(b, a, c));                 // for undirected
    }




    // bellman ford stats here
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;                        // initially setting all as the Max
    }


    dis[0] = 0;                       // source node is 0



    for (int i = 0; i < n - 1; i++)                            // (n-1) times process cholbe
    {

        for (auto ed : edge_list)
        {
            int a, b, c;                                                    // (step-i) edge theke object ber kora hocche

            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])                   // (step-ii) relax
            {
                dis[b] = dis[a] + c;
            }
        }
    }




    for (int i = 0; i < n; i++)                              // printing the shortest path
    {
        cout << i << " -> " << dis[i] << endl;
    }
    

    return 0;
}








/*
Input:
4 4
0 2 5
0 3 12
2 1 2
1 3 3


Output:
0 -> 0
1 -> 7
2 -> 5
3 -> 10


*/