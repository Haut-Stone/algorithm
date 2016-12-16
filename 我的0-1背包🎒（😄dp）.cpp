#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10010;
int dp[110][N];
int c[N] = {0};//单个的重量
int w[N] = {0};//单个的价值

int package(int *w, int *c, int volume, int number);

int main(int argc, char const *argv[])
{
    
    int number;
    int volume;
    int result;
    
    scanf("%d %d", &number, &volume);
    for(int i=1;i<=number;i++){
        scanf("%d %d", &c[i], &w[i]);
    }
    
    result = package(w, c, volume, number);
    printf("%d\n", result);
    return 0;
}

int package(int *w, int *c, int volume, int number)
{
    memset(dp, 0, sizeof(dp));
    int min = 10010;
    for(int i=1;i<=number;i++){
        if(c[i] < min) min = c[i];//取背包里遇到的占据空间最小的。打表需要。
        for(int v=min;v<=volume;v++){
            if(v-c[i] < 0){
                dp[i][v] = dp[i - 1][v];//卡在这里卡了好长时间！！很重要！！
            }else{
                dp[i][v] = max(dp[i-1][v], dp[i-1][v-c[i]] + w[i]);//找之前的最优值
            }
            cout<<"dp["<<i<<"]["<<v<<"]="<<dp[i][v]<<endl;//由于全局变量看不到值，用这一句来检测表中的值。
        }
    }
    return dp[number][volume];
}