#include <bits/stdc++.h>
using namespace std;

void SatDigit(int n, string v[])
{
    if (n == 0)
        return;

    int num = n % 10;
    n /= 10;
    SatDigit(n, v);
    cout << v[num] << " ";
}

int main()
{
    string v[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    SatDigit(415, v);
    return 0;
}
