/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 13:24:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-19 20:46:49
*/

const int N = 100;
const int INF = 99999999;

struct Node
{
	int u;
	int v;
	int w;
}edge[N];

int dis[N];
int vertexs;
int edges;

int bellman(int beginX,int endX)
{
	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
	}
	dis[beginX] = 0;
	for(int k=1;k<vertexs;k++){
		for(int i=1;i<edges;i++){
			if(dis[edge[i].u] != INF && dis[edge[i].v] > dis[edge[i].u] + edge[i].w){
				dis[edge[i].v] = dis[edge[i].u] + edge[i].w;
			}
		}
	}
	return dis[endX];
}