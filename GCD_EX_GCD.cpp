/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 16:35:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 17:07:25
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

//这里仍然返回的是最大公约数，但是通过中间的处理将x, y都算了出来。
//x, y的初始值随意，没有要求
int exGcd(int a, int b, int &x, int &y)
{
	if(b == 0){//开始反推的起点
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exGcd(b, a%b, x, y);
	int temp = x;
	x = y;
	y = temp - (a/b)*y;
	return gcd;
}