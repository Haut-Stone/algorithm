#include <iostream>
using namespace std;
int PowerMod(long long a,long long b,long long c)
{
    int ans=1;
    a = a%c;
    while(b>0){
        if(b%2==1)
            ans=(ans*a)%c;
        b=b/2;
        a=(a*a)%c;
    }
    return ans;
}

int main()
{
    long long a,b,c;
    while(cin>>a>>b>>c)
        cout<<PowerMod(a,b,c)<<endl;
}