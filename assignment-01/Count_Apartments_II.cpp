// https://www.hackerrank.com/contests/assignment-01-a-introduction-to-algorithms-a-batch-06/challenges/Count-apartments-ii

#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool visited_array[1001][1001];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int r, c;

bool valid(int x, int y)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
    {
        return false;
    }
    else
        return true;
}

int Count = 0;
vector<int> v;

void DFS(int sr, int sc)
{
    visited_array[sr][sc] = true;
    Count++;

    for (int i = 0; i < 4; i++)
    {
        int ci = sr + direction[i].first;
        int cj = sc + direction[i].second;

        if (valid(ci, cj) && visited_array[ci][cj] == false && grid[ci][cj] == '.')
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

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '.')
            {
                if (!visited_array[i][j])
                {
                    DFS(i, j);
                    v.push_back(Count);
                    Count = 0;
                }
            }
        }
    }

    if (v.empty())
        cout << '0';

    else
    {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
}