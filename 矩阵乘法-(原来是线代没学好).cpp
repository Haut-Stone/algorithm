#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int m1[200][200];
int m2[200][200];
int ans[200][200];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &m1[i][j])
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &m2[i][j])
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans[i][j] += m1[i][h] * m2[h][j];
			}
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}	
	return 0;
}