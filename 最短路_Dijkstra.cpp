/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-17 14:15:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-18 21:37:13
*/

//在main函数中用邻接矩阵存好图后，直接调用该函数即可。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 110;//根据题目要求更该合适的数值
const int INF = 99999999;
//需要在main中读取的值
int iMap[N][N];
int vertexs;
int beginX = 1;//开始点的位置，一般为1

//仅dijkstra中用到的
int vis[N];
int dis[N];

void dijkstra()
{	
	int min;
	int minVertex;
	int ans = -1;

	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
	}

	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && vis[j] == 0){
				min = dis[j];
				minVertex = j;
			}
		}
		vis[minVertex]  = 1;
		for(int j=1;j<=vertexs;j++){
			if(iMap[minVertex][j] < INF){
				if(dis[minVertex] + iMap[minVertex][j] < dis[j]) dis[j] = dis[minVertex] + iMap[minVertex][j];
			}
		}
	}
	//找出符合一定条件的ans后输出
	//.....这里写条件
	printf("%d\n", ans);
	return;
}