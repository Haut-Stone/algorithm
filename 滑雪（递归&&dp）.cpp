#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int func(int x, int y);
int monitor(void);
int dp[110][110];
int data[110][110];
int myNext[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int n,m;

int main(int argc, char const *argv[])
{
    
    int result = 0;;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &data[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = func(i, j);
            monitor();
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    printf("%d\n", result);
    monitor();
    return 0;
}

int func(int x, int y)
{
    int max = 0;
    int tx;
    int ty;
    if(dp[x][y] > 0) return dp[x][y];
    for(int i=0;i<4;i++){
        tx = x + myNext[i][0];
        ty = y + myNext[i][1];
        if(tx < 1 || ty < 1 || tx > n || ty > m){
            continue;
        }else{
            if(data[x][y] > data[tx][ty] && max < func(tx,ty)) max = func(tx, ty);//确保之前找到的路的最大值不会被冲掉。
        }
    }
    return dp[x][y] = max + 1;
}

int monitor(void)
{
    printf("现在的dp状态是:\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}