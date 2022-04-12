#include <bits/stdc++.h>
using namespace std;

// To calculate "a" to the power "b" (a**b)

int power(int a, int b)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    int ans = power(a, b / 2);
    
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int ans = power(2, 9);
    cout << ans;
    return 0;
}