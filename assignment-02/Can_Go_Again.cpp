// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/can-go-again

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

long long dis[10005];

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
        // edge_list.push_back(Edge(b, a, c));
    }





    // bellman ford stats here
    for (int i = 0; i <= n; i++)
    {
        dis[i] = LONG_MAX;
    }



    int s;
    cin >> s;           // source

    dis[s] = 0;             // source is 0



    for (int i = 1; i <= n; i++)
    {

        for (auto ed : edge_list)
        {
            int a, b, c;

            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != LONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        int a, b, c;

        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] != LONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }



    
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }

    else
    {
        int t;
        cin >> t;

        while (t--)
        {
            int d;
            cin >> d;

            if (dis[d] == LONG_MAX)
            {
                cout << "Not Possible" << endl;
            }

            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}