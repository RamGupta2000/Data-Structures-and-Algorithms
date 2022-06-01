#include <bits/stdc++.h>
using namespace std;

int toh(int n, int src, int dst, int help)
{
    static int count = 0;
    if (n == 0)
    {
        return 0;
    }
    toh(n - 1, src, help, dst);
    cout << "move disk " << n << " from rod " << src << " to rod " << dst << endl;
    count++;
    toh(n - 1, help, dst, src);
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << "Number of moves made : " << toh(n, 1, 3, 2);
    return 0;
}