#include <bits/stdc++.h>
using namespace std;

// To check if given string is palindrome or not

bool checkPalindrome(string s, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (s[i] != s[j])
    {
        return false;
    }
    else
    {
        return checkPalindrome(s, i + 1, j-1);
    }
}

int main()
{
    string s;
    cin >> s;
    bool isPalindrome = checkPalindrome(s, 0, s.size() - 1);

    if (isPalindrome)
    {
        cout << "String is Palidrome";
    }
    else
    {
        cout << "String is not Palidrome";
    }
    return 0;
}