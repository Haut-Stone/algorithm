/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-17 14:15:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-17 15:25:47
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

//以第一个点为起点的迪杰斯特拉算法
int main(void)
{
	int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 99999999;//用来代替正无穷
	scanf("%d %d", &n, &m);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i == j){
				e[i][j] = 0;
			}else{
				e[i][j] = inf;
			}
		}
	}

	for(i=1;i<=m;i++){
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}

	for(i=1;i<=n;i++){
		dis[i] = e[1][i];
	}

	for(i=1;i<=n;i++){
		book[i] = 0;
	}
	book[1] = 1;


	//核心算法
	for(i=1;i<=n-1;i++){
		min = inf;
		for(j=1;j<=n;j++){
			if(book[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for(v=1;v<=n;v++){
			if(e[u][v] < inf){
				if(dis[v] > dis[u] + e[u][v]){
					dis[v] = dis[u] + e[u][v];
				}
			}
		}
	}

	//输出
	for(i=1;i<=n;i++){
		printf("%d ", dis[i]);
	}

    return 0;
}