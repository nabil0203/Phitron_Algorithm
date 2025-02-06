// copied DFS code
// change are commented

// MAIN CODE



#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited_array[1005];

void DFS(int src)
{

//  cout << src << " ";                                  // dont need to print DFS
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


    int count = 0;                                               // count initialized
    for (int i = 0; i < n; i++)                                 // loop on Visited Array
    {
        if (visited_array[i] == false)
        {
            DFS(i);
            count++;                                         // everytime DFS is Initilised, Count increases
        }
        
    }

    cout << count;                                              // count print
    
    return 0;
}