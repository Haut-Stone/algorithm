#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int power(int base, int index);

int main(int argc, char const *argv[])
{
    int base;
    int index;
    int ans;
    int n;
    
    scanf("%d", &n);
    while(n--){
        scanf("%d", &base);
        scanf("%d", &index);
        ans = power(base, index);
        printf("%d\n", ans);
    }
    return 0;
}

int power(int base, int index)
{
    int ans;
    if(index == 0) return 1;
    ans = power(base index/2);//一下为向前回带的过程，所发生的值变化。
    ans = ans * ans;
    if(index%2 != 0) ans = ans * base;
    return ans;
}