int BinarySearch(const ELementType A[], ELementType X, int n){
	int low, mid,high;
	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high)/2;
		if(A[mid] < X){
			low = mid + 1;
		}else if(low > high){
			high = mid - 1; 
		}else{
			return mid;
		}
	}
	return -1;
}

