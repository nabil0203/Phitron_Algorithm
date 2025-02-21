// https://judge.phitron.io/contests/phitron-code-fest1-mock-batch06/problems/cm7a3h4pb00fpqu01j9fsx6bk?language=cpp_105


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c && c == a)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}