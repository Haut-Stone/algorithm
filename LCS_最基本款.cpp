/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-16 17:44:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-16 17:44:38
*/

//最基本的求最大公共子序列(不连续也可以)
//s

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

int dp[N][N];
char a[N];
char b[N];
int aLen;
int bLen;

void init()
{
	memset(dp, 0, sizeof(dp));
}


int main(void)
{
	// INPUT_TEST;

	while(~scanf("%s%s", a, b)){
		init();
		aLen = strlen(a);
		bLen = strlen(b);
		int cnt = 0;
		for(int i=0;i<aLen;i++){
			if(a[i] == b[0]){
				cnt = 1;
			}
			dp[i][0] = cnt;
		}
		cnt = 0;
		for(int i=0;i<bLen;i++){
			if(b[i] == a[0]){
				cnt = 1;
			}
			dp[0][i] = cnt;
		}
		for(int i=1;i<aLen;i++){
			for(int j=1;j<bLen;j++){
				if(a[i] == b[j]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("%d\n", dp[aLen-1][bLen-1]);
	}
	return 0;
}