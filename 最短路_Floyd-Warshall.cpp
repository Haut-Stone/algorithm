/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-18 21:38:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 11:04:25
*/

//有种动态规划的思想，按点的编号，松弛求的最短路径。

const int N = 100;
const int INF = 99999999;

int iMap[N][N];//先组织好图再求最短路
int vertexs;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j]= INF;
			}
		}
	}
}

//求任意两个顶点之间的最短
void floyd()
{
	for(int k=1;k<=vertexs;k++){
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				if(iMap[i][j] > iMap[i][k] + iMap[k][j]){//这就是floyd唯一的判断条件。
					iMap[i][j] = iMap[i][k] + iMap[k][j];
				}
			}
		}
	}
	return;
}