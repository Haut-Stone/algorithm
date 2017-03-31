/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 19:05:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 19:37:06
*/
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

const int N = 100;
const int LEN = 27;

int parents[LEN];
int edgeNumber;

struct Edge
{
	int begin;
	int end;
	int distance;
}edges[N*N];

//比较函数
bool cmp(Edge a, Edge b)
{	
	return a.distance < b.distance;
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
	for(int i=1;i<=LEN;i++){//相当于声明了27个没有叶子的树。
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
		parents[x] = y;//如果不是同一个集合的，则将两个点连起来。
	}
	return false;
}

int kruskal()
{
	sort(edges+1, edges+1+edgeNumber, cmp);
	init();
	int ans = 0;
	for(int i=1;i<=edgeNumber;i++){
		if(hadUnite(edges[i].begin, edges[i].end)){
			continue;
		}else{
			ans += edges[i].distance;//这里在hadUnite函数里已经合并过了。这里不用再合并。
		}
	}
	return ans;
}
