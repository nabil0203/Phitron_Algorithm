// https://www.hackerrank.com/contests/phitron-problem-solvers-club-mock-contest/challenges/here-comes-the-genie-4/problem

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

    sort(a, a + n, greater<>());

    long long int sum = 0, comp = LONG_MAX;

    for (long long int i = 0; i < n; i++)
    {
        if (a[i] >= comp)
        {
            a[i] = comp - 1;
        }

        if (a[i] > 0)
        {
            sum += a[i];
            comp = a[i];
        }
    }

    cout << sum;

    return 0;
}