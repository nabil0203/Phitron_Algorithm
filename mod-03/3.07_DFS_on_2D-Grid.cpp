// fresh code




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

void DFS(int si, int sj)
{
    cout << si << " " << sj << endl;
    visited_array[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci, cj;

        ci = si + d[i].first;
        cj = sj + d[i].second;

        if (valid(ci, cj) && !visited_array[ci][cj])
        {
            DFS(ci, cj);
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

    // DFS starts here
    int si, sj;
    cin >> si >> sj;

    memset(visited_array, false, sizeof(visited_array));

    DFS(si, sj);

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
0 1
1 1
2 1
2 0
1 0
0 0
2 2
2 3
1 3
0 3


*/