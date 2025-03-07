// full code
// O(2^N)



#include <bits/stdc++.h>
using namespace std;

int val[1005], weight[1005];



int knapsack(int i, int max_weight)
{

    if(i < 0 || max_weight <= 0)                             //base case; index 0 er choto hole, weight capacity 0 hole
    {
        return 0;
    }




    if (weight[i] <= max_weight)                                                       // item er weight, max weight er choto/soman hole 2 ta option available
    {
        // 2 options
        // i) bag ee rakhbo, ii) bag ee rakhbo na

        int op1 = knapsack(i - 1, max_weight - weight[i]) + val[i];                                          // (last er ager value, max capacity kombe)+ item er value/price barbe
        int op2 = knapsack(i - 1, max_weight);

        return max(op1, op2);

    }


    else                                                                              // item er weight, max weight er theke boro hole 1 ta option available
    {
        // 1 option
        // i) bag ee rakhbo na

        int op2 = knapsack(i - 1, max_weight);

        return op2;

    }

}



int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int max_weight;
    cin >> max_weight;

    cout << knapsack(n - 1, max_weight);

    return 0;
}







/*

intput:
4                              // koyta item
10 4 7 5                      // value/price of the item
4 3 2 5                       // weight of the item
8                             // max weight capacity

output:
17


*/