/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 19:05:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-25 19:49:28
*/

//注意第一个节点的序号是1
//

#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100;
const int LEN = 27;

int parents[LEN];
int edgeNumber;

struct Edge
{
	int u;
	int v;
	int w;
}edge[N*N];

//比较函数
bool cmp(Edge a, Edge b)
{	
	return a.w < b.w;
}

//并查集的查找
int find(int x)
{
	if(parents[x] == x){//到达根结点的时候
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}	
}

//初始化并查集
void init()
{
	for(int i=1;i<=LEN;i++){
		parents[i] = i;
	}
	return;
}

bool hadUnite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y){
		return true;
	}else{
		parents[y] = x;//如果不是同一个集合的，则将两个点连起来。
	}
	return false;
}

int kruskal()
{
	sort(edge, edge+edgeNumber, cmp);
	init();
	int ans = 0;
	for(int i=0;i<edgeNumber;i++){
		if(hadUnite(edge[i].u, edge[i].v)){
			continue;
		}else{
			ans += edge[i].w;//这里在hadUnite函数里已经合并过了。这里不用再合并。
		}
	}
	return ans;
}
