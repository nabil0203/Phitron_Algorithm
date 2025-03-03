#include <bits/stdc++.h>
using namespace std;

int factorial(int a)
{
    if(a == 1)
    {
        return 1;                                 // factorial of 1 = 1
    }

    int mul = factorial(a-1);                     // 4 porjonto factorial er value store hocche

    return a * mul;                               // 5! = 5 * 4! 
}

int main()
{
    int a; cin >> a;            //5
    
    int Z = factorial(a);

    cout << Z;

    return 0;
}