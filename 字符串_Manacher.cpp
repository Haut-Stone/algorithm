/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 18:14:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-28 17:19:45
*/

//以O(n)的复杂读求解最大回文字串
//马儿拉呀拉，拉呀拉，拉呀拉了个车Σ(￣。￣ﾉ)ﾉ


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 3e5;

char Str[maxn];//初始字符串
char test[maxn];//修改后的字符串
int len1;
int len2;
int p[maxn];//标记数组

int manacher();
int init();

int main(void)
{
	int ans = 0;
	scanf("%s", Str);//根据题目情况，可以改晨gets()
	len1 = strlen(Str);
	init();
	ans = manacher();
	printf("%d\n", ans);
    return 0;
}

int init()
{	
	//初始化字符串
	test[0] = '$';
	test[1] = '#';
	for(int i=0;i<len1;i++){
		test[2*i+2] = Str[i];
		test[2*i+3] = '#';
	}
	len2 = len1*2 + 2;
	test[len2] = '*';
	return 0;
}

int manacher()
{
	//核心算法
	int id = 0;
	int ans = 0;
	int max = 0;
	for(int i=1;i<len2;i++){
		//如果现在的位置，在最大回文子列的内部。
		if(max > i){	
			p[i] = min(p[2*id - i], max - i);
		}else{
			p[i] = 1;
		}
		for(;test[i+p[i]] == test[i-p[i]];p[i]++);
		if(p[i] + i > max){
			max = p[i]+i;
			id = i;
		}
	}
	//最后扫一遍
	for(int i=0;i<len2;i++){
		if(ans < p[i]) ans = p[i];
	}
	return ans-1;//减一之后才是实际值
}