#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
bool comp(string a,string b)
{
    return (a+b > b+a);
}
int main(int argc, char const *argv[])
{
    int n;
    string ans[1000];
    scanf("%d",&n);
    for (int i = 0; i < n;  ++i)
    {
        cin>>ans[i];
    }
    sort(ans,ans+n,comp);
    for (int i = 0; i < n; ++i)
    {
        cout<<ans[i];
    }
    return 0;
}