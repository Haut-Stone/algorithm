/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 19:08:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-06 17:43:37
*/

int MaxSubseqSum(int a[], int n){//在线处理
	int thisSum, maxSum;
	int i;
	thisSum = maxSum = 0;
	for(i=0;i<n;i++){
		thisSum += a[i];//累加
		if(thisSum > maxSum){
			maxSum = thisSum;//更新结果
		}else if(thisSum < 0){
			thisSum = 0;//如果有负的则抛弃掉
		}
	}
	return maxSum;
}