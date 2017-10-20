/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 14:02:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-18 12:30:47
*/

//简介的二进制枚举方式，在搜索中比较好用。。
//

#include <iostream>
using namespace std;

int n;
int a[20];

int main(void)
{
	//简单形式的二进制枚举方式
	for(int i=0;i< 1<<n;i++){
		for(int j=0;j<n;j++){
			a[n-j-1] = i>>j&1;//这里从右向左，依次填充a[i]的状态
		}
	}
    return 0;
}