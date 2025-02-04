#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n]; // array of vector

    // edge connect
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int node;
    cin >> node;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == node)
        {
            for (int x : adj_list[i])
            {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}