/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 19:08:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-23 19:36:10
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
};

int num;
int row, col;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(int beginX, int beginY)
{
	int book[N][N];
	memset(book, 0 ,sizeof(book));
	queue<Node> Q;

	Node solo;
	solo.x = beginX;
	solo.y = beginY;
	solo.steps = 0;

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
				Node temp;
				temp.x = dx;
				temp.y = dy;
				temp.steps = solo.steps + 1;
				book[temp.x][temp.y] = 1;
				Q.push(temp);
			}
		}
	}
	return 0;
}