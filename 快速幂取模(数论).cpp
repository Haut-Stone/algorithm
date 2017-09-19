/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 18:14:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-18 21:24:17
*/

//快速幂。但是并不是矩阵快速幂

#include <iostream>
using namespace std;

int PowerMod(long long a,long long b,long long c)
{
	int ans=1;
	a = a%c;
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		b=b/2;
		a=(a*a)%c;
	}
	return ans;
}

int main()
{
	long long a,b,c;
	while(cin>>a>>b>>c){
		cout<<PowerMod(a,b,c)<<endl;
	}    
} 