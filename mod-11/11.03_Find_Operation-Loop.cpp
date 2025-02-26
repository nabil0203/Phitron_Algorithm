// assume Leader array is given
// here just find operation is performing

// O(N)


#include <bits/stdc++.h>
using namespace std;


int leader[1005];


int find_leader(int node)
{
    while (leader[node] != -1)                        // -1 means the main leader
    {
        node = leader[node];                          // -1 na paoa porjonto, ke kar leader khujte thaka; Finally Leader node return kora
    }

    return node;
    
}



int main()
{
    memset(leader, -1, sizeof(leader));

    leader[0] = 1;                            // manually Leader array is creating
    leader[1] = -1;
    leader[2] = 1;
    leader[3] = 1;
    leader[4] = 5;
    leader[5] = 3;


    cout <<  find_leader(4) << endl;            // 4 er absolute leader ke ber kora hocche(1)

    
    return 0;
}