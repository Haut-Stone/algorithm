/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-09 18:50:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-09 18:52:11
*/

//处理大数情况下的问题，1e18的情况下有效。
//运用了二进制，说明点击下方的链接。a*b mod c = a*(2*b0 + 2*b2 + ... + 2*bn) mod c
//然后还有另外一种处理大大数的方法也在链接里面。
//http://www.360doc.com/content/14/0308/22/3520047_358892807.shtml
//运用了二进制和取余的加法性质。

long long mul(long long a, long long b, long long c)
{
	long long result = 0;
	long long tmp;
	tmp = a%c;
	while(b){
		if(b&1){
			result += tmp;
			if(result >= c){
				result -= c;
			}
		}
		tmp<<=1;
		if(tmp >= c){
			tmp-=c;
		}
		b>>=1;
	}
	return result;
}
