//回去在画图，好好思考一下。
//经过我严谨的思考，数字以类似树的访问方式，以后序遍历的方式存
//入dp中，其中在探寻相当于右子树的部分时，dp数组开始起作用，综合起来像当于每个数字均只被访问一遍
//
//  main.cpp
//  C++_test
//
//  Created by Jack Lee on 2016/12/18.
//  Copyright © 2016年 SJH. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 110;

int a[N][N];
int dp[N][N];

int fun(int x,int y,int base)
{
    if(dp[x][y] != 0) return dp[x][y];
    if(x == base){//到塔底
        dp[x][y] = a[x][y];
        return dp[x][y];
    }else{
        dp[x][y] = max(fun(x+1, y, base), fun(x+1, y+1, base)) + a[x][y];//未到塔底
        return dp[x][y];
    }
}

int main(void)
{
    // INPUT_TEST;
    int result;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d", &a[i][j]);
        }
    }   
    result = fun(0,0,n);
    printf("%d\n", result);
    return 0;
}