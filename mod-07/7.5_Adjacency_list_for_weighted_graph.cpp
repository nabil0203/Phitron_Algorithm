// input of Weighted Graph



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adj_list[n];

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        adj_list[a].push_back({b, w});                      // pushing pair in vector
        adj_list[b].push_back({a, w});
    }

    return 0;
}