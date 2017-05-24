/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 19:04:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-24 13:20:12
*/
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100;
const int INF = (1<<20);

int Imap[N][N];//第一个点的编号从零开始！！
int minCost[N];
bool vis[N];
int vertexNumber;

int prim()
{
	for(int i=0;i<vertexNumber;i++){
		minCost[i] = Imap[0][i];
		vis[i] = false;//初始话顶点为未被访问。
	}

	minCost[0] = 0;//第一个点到自己的距离为0.
	int ans = 0;
	
	while(true){

		int minDis = INF;
		int minPos = 0;

		for(int j=0;j<vertexNumber;j++){
			if(minCost[j] < minDis && !vis[j]){//搜索到当前点的最短距离
				minDis = minCost[j];
				minPos = j;
			}
		}

		if(minDis == INF) break;//如果所有的点都被找过

		vis[minPos] = 1;
		ans += minDis;
		for(int j=0;j<vertexNumber;j++){
			//将已搜索过的点视为一个整体,更新整体的值。
			if(!vis[j] && minCost[j] > Imap[minPos][j]){
				minCost[j] = Imap[minPos][j];
			}
		}
	}
	return ans;
}
