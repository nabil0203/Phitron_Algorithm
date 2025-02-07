// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/can-go-1

#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int r, c;
bool visited_array[1005][1005];
vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int x, int y)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
    {
        return false;
    }
    
    if (grid[x][y] == '#')
        return false;

    else
        return true;
}

void DFS(int si, int sj)
{
    visited_array[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + direction[i].first;
        int cj = sj + direction[i].second;

        if (valid(ci, cj) == true && !visited_array[ci][cj])
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

    memset(visited_array, false, sizeof(visited_array));

    int si, sj, di, dj;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    DFS(si, sj);

    if (visited_array[di][dj] == true)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}