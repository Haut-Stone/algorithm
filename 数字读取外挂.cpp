/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-25 21:33:21
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-25 21:35:49
*/

#include <iostream>

//输入外挂函数
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}

int main(void)
{
	int n;
	n = read();//调用，读取单个整数(不可以是浮点数)。
    return 0;
}