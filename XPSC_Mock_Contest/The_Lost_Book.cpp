// https://www.hackerrank.com/contests/phitron-problem-solvers-club-mock-contest/challenges/the-lost-book

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int tar;
    cin >> tar;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (tar == a[i])
        {
            cout << i;
            flag = true;
            break;
        }
    }

    if (flag == false)
        cout << -1;

    return 0;
}