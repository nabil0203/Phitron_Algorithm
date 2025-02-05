// similar to BFS(v-2.4)
// changes are commented




#include <bits/stdc++.h>
using namespace std;

char grid[105][105];

bool visited_array[105][105];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int c, r;



bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
    {
        return false;
    }
    else
        return true;
}




void BFS(int si, int sj)
{
    queue<pair<int,int>> q;                                 // queue will have a pair in each index; bcz 2D
    q.push({si, sj});
    
    visited_array[si][sj] = true;

    while (!q.empty())
    {
        pair<int,int> par = q.front();                          // pair ber kora hocche
        q.pop();

        int par_i = par.first;                                        // pair alada kora hocche
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;                         // print



        for (int i = 0; i<4; i++)
        {
            int ci = par_i + d[i].first;                                // calculation as DFS
            int cj = par_j + d[i].second ;


            if (valid(ci,cj) && !visited_array[ci][cj])                             // condition check
            {
                q.push({ci, cj});
                visited_array[ci][cj] = true;
            }
        }
    }
}


int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    // BFS starts here
    int si, sj;
    cin >> si >> sj;

    memset(visited_array, false, sizeof(visited_array));

    BFS(si, sj);

    return 0;
}



/*

input:
3 4
....
....
....
1 2


Ouput:
1 2
0 2
2 2
1 1
1 3
0 1
0 3
2 1
2 3
1 0
0 0
2 0



*/