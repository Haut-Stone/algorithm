//
//  main.c
//  拯救小哈（BFS）
//
//  Created by Jack Lee on 2016/11/29.
//  Copyright © 2016年 SJH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{//定义地图区块的结构
    int x;
    int y;
    int step;
}Block;

int main(int argc, char const *argv[])
{
    Block queue[2501];//BFS队列
    int head, tail;//头尾
    int myMap[51][51];//地图
    int book[51][51] = {0};//地图对应的标记，如果该区块走过，则标记为1
    int n, m, startX, startY, endX, endY, tx, ty;
    int flag = 0;//标记是否找到目标
    int next[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};//搜索方向
    
    //读入数据
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &myMap[i][j]);
        }
    }
    scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
    
    //model
    head = 1;//加载初始位置
    tail = 1;
    queue[head].x = startX;
    queue[head].y = startY;
    queue[head].step = 0;
    book[startX][startY] = 1;
    tail++;

    //核心代码
    while(head < tail){
        for(int k=0;k<4;k++){
            tx = queue[head].x + next[k][0];
            ty = queue[head].y + next[k][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;//若该方向越界，寻找下一方向
            if(myMap[tx][ty] == 0 && book[tx][ty] == 0){//符合条件加载至队列
                book[tx][ty] = 1;
                queue[tail].x = tx;
                queue[tail].y = ty;
                queue[tail].step = queue[head].step + 1;
                tail++;
            }
            if(tx == endX && ty == endY){//到达目标
                flag = 1;//跳出for
                break;
            }
        }
        if(flag == 1) break;//跳出while
        head++;//移除搜索过的节点
    }
    printf("%d\n", queue[tail - 1].step);
    return 0;
}
