/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 18:14:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-06 17:47:54
*/

//LCS
//求最长公共子序列

#include <iostream>
#define LEN 100
using namespace std;

int dp[LEN][LEN];
char strA[LEN];
char strB[LEN];
char ans[LEN];
int ptr = 0;
int monitor(int n, int m);

int main(void)
{
    scanf("%s", strA);
    scanf("%s", strB);
    int lengthOfA = (int)strlen(strA);
    int lengthOfB = (int)strlen(strB);
    
    for(int i=1;i<=lengthOfA;i++){
        for(int j=1;j<=lengthOfB;j++){
            if(strA[i-1] == strB[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // monitor(lengthOfA, lengthOfB);

    const int LCS = dp[lengthOfA][lengthOfB];

    int temp1 = lengthOfA;
    int temp2 = lengthOfB;

    while(dp[temp1][temp2]){
        if(dp[temp1][temp2] == dp[temp1-1][temp2]){
            temp1--;
        }else if(dp[temp1][temp2] == dp[temp1][temp2-1]){
            temp2--;
        }else{
            ans[ptr] = strA[temp1-1];
            ptr++;
            temp1--;
            temp2--;
        }
    } 

    for(int i=LCS-1;i>=0;i--){
        printf("%c", ans[i]);
    }
    return 0;
}

// int monitor(int n, int m)
// {
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=m;j++){
//             printf("%d ", dp[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }