/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-10 10:58:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-10 11:03:37
*/

//据说这个UNIX wc程序中的骨干部分
//代码来自The C proramming language

#include <iostream>
#define IN 1
#define OUT 0
using namespace std;

int main(void)
{
	int c;
	int nl, nw, nc, state;
	state = OUT;
	nl = nc = nw = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n'){
			++nl;
		}
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}else if(state == OUT){
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}