//
//  main.c
//  拯救小哈（DFS）
//
//  Created by Jack Lee on 2016/11/28.
//  Copyright © 2016年 SJH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int n, m, endX, endY;
int min = 9999999;
int myMap[51][51], book[51][51] = {0};

void dfs(int x, int y, int step);

int main(int argc, char const *argv[])
{
    int startX, startY;
    
    scanf("%d %d", &n, &m);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &myMap[i][j]);
        }
    }
    
    scanf("%d%d%d%d", &startX, &startY, &endX, &endY);
    book[startX][startY] = 1;
    dfs(startX, startY, 0);
    printf("%d\n", min);
    return 0;
}

void dfs(int x, int y, int step)
{
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int tx, ty;
    if(x == endX && y == endY){
        if(step < min) min = step;
        return;
    }
    for(int k=0;k<4;k++){
        tx = x + next[k][0];
        ty = y + next[k][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m){
            continue;
        }
        if(myMap[tx][ty] == 0 && book[tx][ty] == 0){
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}