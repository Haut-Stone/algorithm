#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MIN=0x80000000;
const int N=3;   //物品数量
const int V=5;  //背包容量
int f[N+1][V+1];

int Package(int *W,int *C,int N,int V);
int main(int argc,char *argv[])
{
    int W[4]={0,7,5,8};      //物品权重
    int C[4]={0,2,3,4};      //物品大小
    int result=Package(W,C,N,V);
    if(result>0)
    {
        cout<<endl;
        cout<<"the opt value:"<<result<<endl;
        int i=N,j=V;
        while(i)
        {
            if(f[i][j]==(f[i-1][j-C[i]]+W[i]))
            {
                cout<<i<<":"<<"w="<<W[i]<<",c="<<C[i]<<endl;
                j-=C[i];
            }
            i--;
        }
    }
    else
        cout<<"can not find the opt value"<<endl;
    return 0;
}

int Package(int *W,int *C,int N,int V)
{
    int i,j;
    memset(f,0,sizeof(f));  //初始化为0
    
    for(i=0;i<=N;i++)
        for(j=1;j<=V;j++)               //此步骤是解决是否恰好满足背包容量，
            f[i][j]=MIN;                //若“恰好”满足背包容量，即正好装满背包，则加上此步骤，若不需要“恰好”，则初始化为0
    
    for(i=1;i<=N;i++)
        for(j=C[i];j<=V;j++)
        {
            f[i][j]=(f[i-1][j]>f[i-1][j-C[i]]+W[i])?f[i-1][j]:(f[i-1][j-C[i]]+W[i]);
            cout<<"f["<<i<<"]["<<j<<"]="<<f[i][j]<<endl;
        }
    return f[N][V];
}