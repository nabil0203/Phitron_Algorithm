// copied DFS code
// change are commented
// this shows the components



#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_array[1005];

void DFS(int src)
{
    cout << src << " ";
    visited_array[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited_array[child])
        {
            DFS(child);
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

    for (int i = 0; i < n; i++)                                 // loop on Visited Array
    {
        if (visited_array[i] == false)
        {
            DFS(i);
            cout << endl;                                   // this shows the components
        }
        
    }
    
    return 0;
}








/*

Input:
8 6
1 2
0 5
2 3
6 7
4 5
1 3

Output:
0 5 4 
1 2 3 
6 7

*/