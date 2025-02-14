// https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-06/challenges/same-component


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

    if (grid[x][y] == '-')
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

    cin >> si >> sj;
    cin >> di, dj;

    DFS(si, sj);

    if (visited_array[di][dj] == true)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}