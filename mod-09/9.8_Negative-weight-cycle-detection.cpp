// how Bellman solves the problem of Dijkstra
// 'negative weighted cycle' problem

// same code as 9.5
// je input Dijkstra te infinity te jaito, oi input diye Bellman execute kora hocche
// kono infinity te jay na



#include <bits/stdc++.h>
using namespace std;

class Edge
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

int dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    // bellman ford stats here
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++)                                 // path relax fixed time hocche, tai Infinite loop hocche na
    {

        for (auto ed : edge_list)
        {
            int a, b, c;

            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool cycle = false;
    for (auto ed : edge_list)                                   // extra ekbar chalano hocche mane ekbar besi path relax hocche kina check hocche Negative Detect korar jonno
    {
        int a, b, c;

        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] != INT_MAX && dis[a] + c < dis[b])                        // ekta value update holei/ekbar besi relax holei, bole deya jabe je Negative cylce ase
        {
            cycle = true;
            break;
        }
    }

    
    if (cycle)
    {
        cout << "Negative Weighted Cycle Detected";
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }



    return 0;
}




/*
Input-1:
4 4
0 1 5
1 2 3
2 3 2
3 1 -6

Output-1:
Negative Weighted Cycle Detected



Input-2:
4 4
0 1 5
1 2 3
2 3 2
1 3 -6

Output-2:
0 -> 0
1 -> 5
2 -> 8
3 -> -1



*/
