// Only child print
// Completed code-->(3.07)



#include <bits/stdc++.h>
using namespace std;


char grid[105][105];

bool visited_array[105][105];

vector<pair<int, int>> d = {{-1,0},{1,0},{0,-1},{0,1}};                     // a vector of pairs; every index has a Pair of the calculated part(B-245)

void DFS(int si, int sj)
{
    cout << si << " " << sj << endl;
    visited_array[si][sj] = true;


   for (int i = 0; i < 4; i++)                                     // assuming the Source node has 4 children
   {
        int ci, cj;                                                // child index

        ci = si + d[i].first;                                       // B-247
        cj = sj + d[i].second;

        cout << ci << " " << cj << endl;                            // printing the child
   }
   
}



int main()
{
    int r, c;
    cin >> r >> c;

//  char grid[r][c];            // declared Globally for accessing from anywhere


    for (int i = 0; i < r; i++)                     // input GRID
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }



    // DFS starts here
    int si, sj;                          // index of source node; Where to start
    cin >> si >> sj;

    DFS(si, sj);                       // DFS function calling


    return 0;
}









/*

Input:
3 4
....
....
....
1 2

output:
1 2
0 1
2 1
1 0
1 2


*/