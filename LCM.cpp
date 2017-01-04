/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-04 11:58:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-04 12:09:49
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

long long gcd(long long a, long long b);
int main(void)
{
	long long a;
	long long b;
	long long g = 0;
	long long ans = 0;
	scanf("%lld %lld", &a, &b);
	g = gcd(a, b);
	ans = a*b/g;
	printf("%lld\n", ans);
    return 0;
}

long long gcd(long long a, long long b)
{
	long long c = a%b;
	while(c){
		a = b;
		b = c;
		c = a%b;
	}
	return b;
}