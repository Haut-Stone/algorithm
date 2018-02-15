/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-25 21:29:00
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-30 10:00:47
*/

//这里先写一份注释吧，其实KMP算是实际上就是，利用相同部分的前缀和后缀，从而掉过了重复查找的部分。
//除了KMP算法，还有别的优秀的算法，例如sunday算法。效率比KMP还要高。


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

const int N = 30;
int my_next[N];

void getNext(char str[], int len)
{
	int j = -1;
	my_next[0] = -1;
	for(int i=1;i<len;i++){
		while(j != -1 && str[i] != str[j+1]){
			j = my_next[j];
		}
		if(str[i] == str[j+1]){
			j++;
		}
		my_next[i] = j;
	}
}

/*
	！！单单是统计次数的话，只用把有ans的行取消掉注释就好了！！
*/
bool kmp(char text[], char pattern[])
{
	
	// int lastPos = -1;
	// int ans = 0;
	int n = (int)strlen(text);
	int m = (int)strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = my_next[j];
		}
		if(text[i] == pattern[j+1]){
			// if(lastPos < i) lastPos = i;
			j++;
		}
		if(j == m-1){//出现匹配，则存在
			// ans++;
			// j = my_next[j];
			// return lastPos - m + 2;//首次出现的位置
			return true;//是否存在
		}
	}
	// return ans;//返回一共匹配出现了几次
	return false;
}

int main(void)
{
	char text[N] = "abababaabc";
	char pattern[N] = "ababaab";
	kmp(text, pattern);
	return 0;
}