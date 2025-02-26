// same as 11.07
// took graph input as Edge list


#include <bits/stdc++.h>
using namespace std;


int leader_array[1005];
int size_array[1005];



int find_leader(int node)                            // find operation
{
    if (leader_array[node] == -1)
    {
        return node;
    }

    int leader = find_leader(leader_array[node]);
    
    leader_array[node] = leader;

    return leader;
}



void dsu_Union(int node1, int node2)                // Union operation
{
    int leader1 = find_leader(node1);
    int leader2 = find_leader(node2);




    if(size_array[leader1] > size_array[leader2])
    {
        leader_array[leader2] = leader1;;

        size_array[leader1] += size_array[leader2];
    }



    else
    {
        leader_array[leader1] = leader2;

        size_array[leader2] += size_array[leader1];
    }

}



int main()
{
    memset(leader_array, -1, sizeof(leader_array));
    memset(size_array, 1, sizeof(size_array));

    
    int n, e;                           // edge input
    cin >> n >> e;

    bool cycle = false;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find_leader(a);             // finding the leaders
        int leaderB = find_leader(b);

        if(leaderA == leaderB)                    // if same leader, then "Cycle detected"
        {
            cycle = true;
        }
        else
            dsu_Union(a,b);                       // if not, then union those nodes
    }



    if(cycle)
        cout << "Cycle Detected" << endl;
    else
        cout<< "No cycle" <<endl;



    return 0;
}









/*

Input-1:
6 6
0 1
1 2
0 4
4 5
5 3
3 4

Output-1:
Cycle Detected



Input-2
6 5
0 1
1 2
0 4
4 5
3 4

Output-2:
No cycle




Input-3:
2 1                 // 2 node, 1 edge
0 1

Output-3:
No cycle


*/