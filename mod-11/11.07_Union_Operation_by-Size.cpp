// Union Operation is used to Make Connection between 2 sets
// find operation is also here



#include <bits/stdc++.h>
using namespace std;


int leader_array[1005];
int size_array[1005];                     // size_array used to track the size of each Set



int find_leader(int node)
{
    if (leader_array[node] == -1)
    {
        return node;
    }

    int leader = find_leader(leader_array[node]);
    
    leader_array[node] = leader;

    return leader;
}



void dsu_Union(int node1, int node2)
{
    int leader1 = find_leader(node1);                   // step(i)--> Find the leader of each node (leader of 1 & 2)
    int leader2 = find_leader(node2);




    if(size_array[leader1] > size_array[leader2])              // if size of set-1 is bigger
    {
        leader_array[leader2] = leader1;                      //  then the leader of set-2 is changed to set-1's leader

        size_array[leader1] += size_array[leader2];           // as two sets are joined now; size has increase of the set-1
    }



    else                                                               // if size of set-2 is bigger
    {
        leader_array[leader1] = leader2;                               // then the leader of set-1 is changed to set-2's leader

        size_array[leader2] += size_array[leader1];                   // as two sets are joined now; size has increase of the set-2
    }

}



int main()
{
    memset(leader_array, -1, sizeof(leader_array));
    memset(size_array, 1, sizeof(size_array));

    
    dsu_Union(1,2);                         // making Connection between 1 & 2
    dsu_Union(2,0);
    dsu_Union(3,1);



    // printing parent of each node

    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << leader_array[i] << endl;
    }
    

    return 0;
}