// bottom-up


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    int fibo[n+5];

    fibo[0] = 0;                    // first 2 value
    fibo[1] = 1;


    for (int i = 2; i <= n; i++)            // starts from 3rd index
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[n];


    return 0;
}