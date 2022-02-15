#include<bits/stdc++.h>
using namespace std;

// To reverse a given string

void reverse(string &s,int i,int j)
{
    if(i>j)
    {
        return;
    }
    swap(s[i],s[j]);
    i++; j--;
    reverse(s,i,j);
    
//     if (i > s.size() - 1 - i)
//     {
//         return;
//     }
//     swap(s[i], s[s.size() - 1 - i]);
//     i++;

//     reverse(s, i, s.size() - 1 - i);

}

int main()
{
    string s;
    cin>>s;
    reverse(s,0,s.size()-1);
    cout<<s;
    return 0;
}
