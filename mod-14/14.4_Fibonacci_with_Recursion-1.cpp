// fibonacci means--> kono number er ager 2ta number er jogfol
// that's why the first 2 values of fibonacci series are FIXED ----> 0 1
// third value = 0 + 1 = 1
// fourth value = 1 + 1 = 2

// fibonacci index-  0   1   2   3   4   5   6   7   8    9...........
// Fibonacci Series- 0   1   1   2   3   5   8   13  21  34............




#include <bits/stdc++.h>
using namespace std;

int fibo(int a)
{
    if(a == 0)                      // 2 base cases; bcz these 2 are FIXED
    {
        return 0;
    }

    if(a == 1)
    {
        return 1;
    }



    return fibo(a-1) + fibo(a-2);                 // fibonacci of 5 = (fibonacci of 4 + fibonacci of 3)
}



int main()
{
    int a; cin >> a;        // fibonacci series has index; ami je index er Fibonacci value jante chai oi index input

    cout << fibo(a);


    return 0;
}