// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/connected-nodes-1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a;
        cin >> a;

        
        sort(adj_list[a].begin(), adj_list[a].end(), greater<>());


        if (adj_list[a].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            for (int x : adj_list[a])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}