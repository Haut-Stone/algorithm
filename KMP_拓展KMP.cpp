/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 15:12:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-19 14:30:15
*/

//
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

//这个过程还是比较简单的
void getNext(string & T, int & m, int next[])
{
	int firstPos = 0;
	int lastPos = 0;
	next[0] = m;
	
	for(int i=1;i<m;i++){
		//                      这里其实就是划了一个椭圆的范围，不用再计算了
		if(i >= lastPos || i + next[i - firstPos] >= lastPos){
			if(i >= lastPos){
				lastPos = i;
			}
			while(lastPos < m && T[lastPos] == T[lastPos - i]){
				lastPos++;
			}
			next[i] = lastPos - i;
			firstPos = i;
		}else{
			next[i] = next[i - firstPos];
		}
	}
}

void getExtend(string & S, int & n, string & T, int & m, int extend[], int next[])
{
	int firstPos = 0;
	int lastPos = 0;
	
	getNext(T, m, next);
	for(int i=0;i<n;i++){
		if(i >= lastPos || i + next[i - firstPos] >= lastPos){
			if(i >= lastPos){
				lastPos = i;
			}
			while(lastPos < n && lastPos - i < m && S[lastPos] == T[lastPos - i]){
				lastPos++;
			}
			extend[i] = lastPos - i;
			firstPos = i;
		}else{
			extend[i] = next[i - firstPos];
		}
	}
}

int main()
{
	int next[100];
	int extend[100];
	string S, T;
	int n, m;
	
	while (cin >> S >> T)
	{
		n = (int)S.size();
		m = (int)T.size();
		getExtend(S, n, T, m, extend, next);
		
		// 打印 next 和 extend
		cout << "next:   ";
		for (int i = 0; i < m; i++)
			cout << next[i] << " ";
		cout << "\nextend: ";
		for (int i = 0; i < n; i++)
			cout << extend[i] << " ";
		cout << endl << endl;
	}
	return 0;
}
