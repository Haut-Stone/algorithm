int MaxSubseqSum4(int a[], int n){//在线处理
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