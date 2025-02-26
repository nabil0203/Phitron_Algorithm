// same as recursion
// extra line added

// O(logN)



#include <bits/stdc++.h>
using namespace std;


int leader_array[1005];


int find_leader(int node)
{
    if (leader_array[node] == -1)                               // base case
    {
        return node;
    }

    int leader = find_leader(leader_array[node]);            // recursion called
    
    leader_array[node] = leader;                                  // optimised line; setting connection with the Main leader Directly

    return leader;
}




int main()
{
    memset(leader_array, -1, sizeof(leader_array));

    leader_array[0] = 1;
    leader_array[1] = -1;
    leader_array[2] = 1;
    leader_array[3] = 1;
    leader_array[4] = 5;
    leader_array[5] = 3;

    cout << find_leader(4) << endl;

    return 0;
}