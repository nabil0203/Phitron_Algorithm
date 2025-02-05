// at first check (2.8_Shortest_Distance)
// then check (3.09_DFS_on_2D-Grid-1)
// then Check this shortest distace
// change against (3.09_DFS_on_2D-Grid-1) are commented




#include <bits/stdc++.h>
using namespace std;

char grid[105][105];

bool visited_array[105][105];

int level[105][105];                                              // we need level

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
    queue<pair<int,int>> q;
    q.push({si, sj});
    
    visited_array[si][sj] = true;

    level[si][sj] = 0;                           // level of Source is '0'

    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

//      cout << par_i << " " << par_j << endl;                      // BFS print not needed



        for (int i = 0; i<4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second ;


            if (valid(ci,cj) && !visited_array[ci][cj])
            {
                q.push({ci, cj});
                visited_array[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
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
    int si, sj, di,dj;                      // di,dj initialized
    cin >> si >> sj >> di >> dj;

    memset(visited_array, false, sizeof(visited_array));
    memset(level, -1, sizeof(level));                         // level as '-1'

    BFS(si, sj);


    cout << level[di][dj];


    return 0;
}



/*

input:
3 4
....
....
....
1 2                         // source
2 0                          // destination


Ouput:
3




*/