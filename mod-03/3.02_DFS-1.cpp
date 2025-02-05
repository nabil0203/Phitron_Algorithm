#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];             // Adjacency list; Global 'array of vector'

bool visited_array[1005];        // Visited Array to Track




void DFS(int src)
{
    // base code-----step(i)
    // base case lagbe na; bcz Visited track rakha hocche; So, kono node duibar call hobe na





    // kaj kora-----step(ii)
    cout << src << " ";
    visited_array[src] = true;                                 // visit hoile true kore deya; jate same node track thake ar ekbarer besi visit na hoy 




    // -----step(iii)
    for(int child : adj_list[src])
    {
        if(!visited_array[child])                                // child not visited thaklei DFS call korbo
        {
            DFS(child);
        }
    }
}





int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited_array,false,sizeof(visited_array));                          // setting Visiting Array False


    DFS(0);                                  // calling DFS


    return 0;
}



/*

Input:
7 7
0 2
2 4
0 1
1 5
1 3
0 3
3 6

output:
0 2 4 1 5 3 6



*/