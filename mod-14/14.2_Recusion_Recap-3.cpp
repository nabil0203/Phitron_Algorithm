// sum sum of 1-5

#include <bits/stdc++.h>
using namespace std;

int sum(int a)
{

    if (a > 5)
    {
        return 0;
    }

    int total_sum = sum(a + 1);                     // 1 er pore, mane 2-5 er sum joma hocche total_sum ee

    return total_sum + a;                           // 2-5 er sum er sathe 1 jog hocche
}

int main()
{
    int a;
    cin >> a;           // 1

    cout << sum(a);

    return 0;
}