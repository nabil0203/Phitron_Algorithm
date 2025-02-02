#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int,int>> edge_list;                          // pair type vector; each index of Vector has a Pair



    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a,b});                            // pushing a pair in in each index
    }


    for (pair<int,int> x : edge_list)                          // print
    {
        cout << x.first << " " <<x.second << endl;
    }
    
    

    return 0;
}