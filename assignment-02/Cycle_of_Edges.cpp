// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-06/challenges/cycle-of-edges




#include <bits/stdc++.h>
using namespace std;


int leader_array[1000005];
int size_array[1000005];


int find_leader(int node)                           // find operation
{
    if (leader_array[node] == -1)
    {
        return node;
    }

    int leader = find_leader(leader_array[node]);

    leader_array[node] = leader;

    return leader;
}



void dsu_Union(int node1, int node2)                        // Union operation
{
    int leader1 = find_leader(node1);
    int leader2 = find_leader(node2);

    if (size_array[leader1] > size_array[leader2])
    {
        leader_array[leader2] = leader1;
        ;

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

    int n, e;                               // edge input
    cin >> n >> e;

    int cycle = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find_leader(a);           // finding the leaders
        int leaderB = find_leader(b);

        if (leaderA == leaderB)                 // if same leader, then "Cycle detected"
        {
            cycle++;
        }
        else
            dsu_Union(a, b);                    // if not, then union those nodes
    }

    cout << cycle << endl;

    return 0;
}