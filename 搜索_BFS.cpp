/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 19:08:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 09:04:45
*/

//这个示例是二维地图bfs的大致步骤
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1010;

struct Node
{
	int x;
	int y;
	int steps;
	Node(){};
	Node(int X, int Y, int STEPS){
		x = X;
		y = Y;
		steps = STEPS;
	}
};


int num;
int row, col;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(int beginX, int beginY)
{
	int book[N][N];
	memset(book, 0 ,sizeof(book));
	queue<Node> Q;

	Node solo(beginX, beginY, 0);
	Q.push(solo);
	book[solo.x][solo.y] = 1;

	while(!Q.empty()){
		solo = Q.front();
		Q.pop();

		for(int i=0;i<4;i++){
			int dx = solo.x + direction[i][0];
			int dy = solo.y + direction[i][1];
			//如果该点合法	，加入队列
			if(dx >= 0 && dy >= 0 && dx <= row && dy <= col){
				Node temp(dx, dy, solo.steps+1);
				book[temp.x][temp.y] = 1;
				Q.push(temp);
			}
		}
	}
	return 0;
}