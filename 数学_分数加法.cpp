/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-28 08:43:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-02 21:31:34
*/

#include <iostream>
using namespace std;
#define ll long long
const int N = 100;

struct Fraction
{
	ll up;
	ll down;
}number[N];

//求最大公约数
ll gcd(ll a, ll b)
{
    if(b == 0){
        return abs(a);
    }else{
        return gcd(b, a%b);
    }
}

//约分
Fraction reduction(Fraction result)
{
	if(result.down < 0){
		result.up = -result.up;
		result.down = -result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		ll temp = gcd(abs(result.up), abs(result.down));
		result.up /= temp;
		result.down /= temp;
	}
	return result;
}

//相加
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

int main(void)
{
	int n;
	Fraction ans;
	ans.up = 0;
	ans.down = 1;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld/%lld", &number[i].up, &number[i].down);
		number[i] = reduction(number[i]);
		ans = add(ans, number[i]);
	}
	//输出n个分数的和
	if(ans.down == 1){
		printf("%lld\n", ans.up);
	}else{
		if(ans.up > ans.down){
			printf("%lld %lld/%lld\n", ans.up/ans.down, ans.up % ans.down, ans.down);
		}else{
			printf("%lld/%lld\n", ans.up, ans.down);
		}
	}
	return 0;
}