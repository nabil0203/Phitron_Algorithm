// https://www.hackerrank.com/contests/phitron-problem-solvers-club-final-contest-batch-6/challenges/array-reconstruction

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n;
        cin >> n;

        int a[n];
        long long int sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        long long int given_sum;
        cin >> given_sum;

        long long int differnce = given_sum - sum;

        cout << differnce + 1 << endl;
    }

    return 0;
}