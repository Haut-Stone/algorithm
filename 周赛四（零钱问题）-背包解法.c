#include"stdio.h"
#include"string.h"
int min(int a,int b)  
{  
    return a>b?b:a;  
}  
int dp[110];  
int main()  
{  
    int n,m,k,i,j;  
    int a[6]={1,2,5,10,50};  
    while(scanf("%d",&n)!=EOF)  
    {  
        m=100-n;  
        memset(dp,0x3f3f3f,sizeof(dp));  
        dp[0]=0;  
        for(i=0;i<5;i++)  
        {  
            for(j=a[i];j<=m;j++)  
            {  
                dp[j]=min(dp[j],dp[j-a[i]]+1);  
            }  
        }  
        printf("%d %d\n",m,dp[m]);  
    }  
    return 0;  
}  