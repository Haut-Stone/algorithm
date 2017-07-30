/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 10:10:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-28 10:11:25
*/

//线段树的单点更新模版
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


#define MAX 100005
#define lid (id<<1)
#define rid (id<<1|1)


int a[MAX];
int T;
int cas;
int leafNum;

struct Node
{
	int l;
	int r;
	int sum;
}segTree[MAX*4];

void push_up(int id)
{
	segTree[id].sum = segTree[lid].sum + segTree[rid].sum;
}

void bulid(int id, int l, int r)
{	
	segTree[id].l = l;
	segTree[id].r = r;
	if(l == r){
		segTree[id].sum = a[l];//到达叶子时直接返回
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	bulid(lid, l, mid);
	bulid(rid, mid+1, r);
	push_up(id);//对节点求和
}

void update(int id, int x, int val)
{
	if(segTree[id].l == segTree[id].r){
		segTree[id].sum += val;//到达该节点的时候更新值
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	//这里必须这样写因为建树的时候mid在左区间里面
	if(x <= mid){
		update(lid, x, val);
	}else{
		update(rid, x, val);
	}
	push_up(id);//将父节点的值全部更新掉
}

int query(int id, int l, int r)
{
	if(segTree[id].l == l && segTree[id].r == r){
		return segTree[id].sum;//单个区间的话，直接返回
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(r <= mid){
		return query(lid, l, r);
	}
	if(l > mid){
		return query(rid, l, r);
	}
	return query(lid, l, mid) + query(rid, mid+1, r);
}

int main(void)
{
	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d", &leafNum);
		for(int i=1;i<=leafNum;i++){
			scanf("%d", &a[i]);
		}
		bulid(1, 1, leafNum);
		string str;
		printf("Case %d:\n", cas);
		while(cin>>str){
			if(str[0] == 'Q'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);
				int ans = query(1, t1, t2);//查询一个区间和
				printf("%d\n", ans);
			}else if(str[0] == 'A'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);//增加人数
				update(1, t1, t2);
			}else if(str[0] == 'S'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);//减少人数
				t2 = t2 * (-1);
				update(1, t1, t2);
			}else{
				break;
			}
		}
	}
	return 0;
}