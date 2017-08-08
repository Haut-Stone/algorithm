/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2016-12-23 21:37:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 16:27:32
*/

//欧几里得算法
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int gcd(int a, int b);

int main(void)
{
	int T;
	int ans;
    int a;
    int b;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &a, &b);
		ans = gcd(a, b);
		printf("%d\n", ans);
	}
    return 0;
}

//用于求a, b的最大公约数。
//
int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
