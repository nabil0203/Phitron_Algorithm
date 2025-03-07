// not full code
// basic structure



#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];




int knapsack(int i,int max_weight)
{
    // 2 options
    // i) bag ee rakhbo, ii) bag ee rakhbo na
    // duitar moddhe jeta max hobe oita return

    int op1 = knapsack(i-1, max_weight - weight[i]);              // "i-1" last er ager value niye kaj hocche; "max_weight - weight[i]" bag ee item rakha hoole bag er max capacity kombe
    int op2 = knapsack(i-1, max_weight);                          // bag ee rakha na hoole bag er mx capacity same

    return max(op1,op2);
}





int main()
{
    int n;                                        // number of Items
    cin >> n;

    for (int i = 0; i < n; i++)                   // value of the items
    {
        cin >> val[i];
    }
    
    for (int i = 0; i < n; i++)                  // price of the items
    {
        cin >> weight[i];
    }
    

    
    int max_weight;                              // max capacity of the bag
    cin >> max_weight;



    knapsack(n-1, max_weight);                    // last value theke shuru-->(n-1)index; max capacity of the bag


    return 0;
}